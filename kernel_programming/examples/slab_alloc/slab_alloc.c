#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

#define MOD_NAME "slab_alloc"

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("usage of slab api");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

static char *gkptr;

struct mycontext {
    u32 iarr[100];
    u64 uarr[100];
    char uname[128], passwd[16], config[16];
};

static struct mycontext *ctx;

static int __init slab_alloc_init(void)
{
    pr_info("%s: has be initialized");

    gkptr = kmalloc(1024, GFP_KERNEL);

    if (!gkptr) {
        goto out_fail;
    }

    pr_info("kmalloc() succeeds, ret value: %px\n", gkptr);

    print_hex_dump_bytes("gkptr before memset: ",  DUMP_PREFIX_OFFSET, gkptr, 32);

    memset(gkptr, 'm', 1024);

    print_hex_dump_bytes("gkptr after memset: ", DUMP_PREFIX_OFFSET, gkptr, 32);

    ctx = kzalloc(sizeof(struct mycontext), GFP_KERNEL);

    if (!ctx) {
        goto out_fail2;
    }

    pr_info("kzalloc succeeded, ret value: %px\n", ctx);

    print_hex_dump_bytes("cts: ", DUMP_PREFIX_OFFSET, ctx, 32);


    return 0;

out_fail2:
    kfree(gkptr);
out_fail:
    return -ENOMEM;

}

static void __exit slab_alloc_exit(void)
{
    pr_info("%s: has be removed");
    kfree(ctx);
    kfree(gkptr);

}

module_init(slab_alloc_init);
module_exit(slab_alloc_exit);