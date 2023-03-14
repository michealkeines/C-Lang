#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/sched.h>

#define MODENAME "custom_slab"

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("custom struct slab");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

static int use_constructor = 1;
module_param(use_constructor, uint, 0600);
MODULE_PARM_DESC(use_constructor, "if set to 1, our customer constructor will be used");

#define CACHENAME "custom-cache"

struct custom_struct {
    u32 iarr[10];
    u64 uarr[10];
    char uname[128], passwd[16], config[64];
};

static struct kmem_cache *custom_cache_loc;

void custom_constructor(void *allocated_mem)
{
    pr_info("custom constructor called");
    struct custom_struct *ctx = allocated_mem;
    
    memset(ctx, 0, sizeof(struct custom_struct));

    snprintf(ctx->uname, 7, "kaines\0");
    snprintf(ctx->passwd, 9, "password\0");
    snprintf(ctx->config, 5, "test\0");
}


static int create_custom_cache(void)
{
    void *c_func = NULL;

    if (use_constructor) {
        c_func = custom_constructor;
    }

    pr_info(
        "size of our structure is %zu bytes\n"
        "using constructor %s\n", sizeof(struct custom_struct), use_constructor == 1 ? "yes" : "no"
    );

    custom_cache_loc = kmem_cache_create(
        CACHENAME,
        sizeof(struct custom_struct),
        sizeof(long),
        SLAB_POISON | SLAB_RED_ZONE | SLAB_HWCACHE_ALIGN,
        c_func
    );

    if (!custom_cache_loc) {
        pr_info("kmem_cache_create failed\n");
        return -1;
    }

    return 0;
}

static int use_custom_cache(void)
{
    struct custom_struct *our_struct = NULL;

    our_struct = kmem_cache_alloc(custom_cache_loc, GFP_KERNEL);

    if (!our_struct) {
        pr_info("obj allocation failed");
        return -1;
    }

    pr_info("our custom struct:\nname: %s\npass: %s\nconfig: %s\n",
        our_struct->uname, our_struct->passwd, our_struct->config
    );

    pr_info(
        "allocated obj: %pK, actual: %px, size is %u bytes, actual alloc size %zu\n",
        our_struct, our_struct, kmem_cache_size(custom_cache_loc), ksize(our_struct)
    );

    print_hex_dump_bytes("obj: ", DUMP_PREFIX_OFFSET, our_struct, sizeof(struct custom_struct));

    kmem_cache_free(custom_cache_loc, our_struct);

    return 0;
}


static int __init custom_slab_init(void)
{
    pr_info("custom slab has been added");

    int created_cache;

    created_cache = create_custom_cache();
    pr_info("created custom cache");

    if (created_cache == -1) {
        pr_info("creation failed");
        return -1;
    }


    pr_info("using custom cache");
    use_custom_cache();

    return 0;
}

static void __exit custom_slab_exit(void)
{
    kmem_cache_destroy(custom_cache_loc);
    pr_info("custom slab has been removed");
}

module_init(custom_slab_init);
module_exit(custom_slab_exit);