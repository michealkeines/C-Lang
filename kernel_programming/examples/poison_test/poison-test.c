#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/sched.h>

#define MODENAME "poison_test"
#define CACHENAME "poison_cache"

static int use_constructor;
module_param(use_constructor, int, 0600);
MODULE_PARM_DESC(use_constructor, "if set to 1, our custom constructor will be executed during every allocation");

MODULE_AUTHOR("micheal keines");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("module to test the poisoning of cache allocation");

struct network_data {
    char source_ip[32];
    char destination_ip[32];
    int source_port;
    int destination_port;
};

static struct kmem_cache *custom_cache;
struct network_data *udp_packet;

static int custom_constructor(void *allocated_mem)
{
    pr_info("%s: custom constructor called", MODENAME);

    return 0;
}

static int create_custom_cache(void)
{
    void *construction_fn = NULL;

    if (use_constructor) {
        construction_fn = custom_constructor;
    }

    pr_info("sizeof our structure is %zu bytes\n"
        " using custom constructor routine: %s?\n", sizeof(struct network_data), use_constructor ? "yes" : "no"
    );

    custom_cache = kmem_cache_create(
        CACHENAME,
        sizeof(struct network_data),
        sizeof(long),
        SLAB_POISON | SLAB_RED_ZONE | SLAB_HWCACHE_ALIGN, 
        construction_fn
    );

    if (!custom_cache) {
        pr_info("%s: cache allocation failed\n", MODENAME);
        return -1;
    }
    return 0;
}

static void use_the_object(void *address, char input, size_t n)
{
    memset(address, input, n);
    print_hex_dump_bytes("network_data in use: ", DUMP_PREFIX_OFFSET, address, sizeof(struct network_data));
}

static void use_custom_cache(void)
{
    pr_info("%s: allocation object in our custom cache", MODENAME);
    udp_packet = kmem_cache_alloc(
        custom_cache,
        GFP_KERNEL
    );

    print_hex_dump_bytes("network_data: ", DUMP_PREFIX_OFFSET, udp_packet, sizeof(struct network_data));

    use_the_object(udp_packet, 'z', 16);
}



static int __init poison_test_init(void)
{
    pr_info("%s: module has been initialized", MODENAME);
    create_custom_cache();
    use_custom_cache();
    return 0;
}

static void __exit poison_test_exit(void)
{
    pr_info("%s: module has been removed", MODENAME);
    kmem_cache_free(custom_cache, udp_packet); // freeing udp_packet

    use_the_object(udp_packet, 'z', 16); // using udp_packet mem after freeing

    kmem_cache_destroy(custom_cache);
    pr_info("%s: cache and objects are freed\n");
}

module_init(poison_test_init);
module_exit(poison_test_exit);
