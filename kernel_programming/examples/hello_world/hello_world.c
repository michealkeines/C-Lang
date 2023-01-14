#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
// #include <stdio.h>

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("Hello world module");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.0.1");

static int __init hello_world_inti(void)
{
    printk( KERN_INFO "Hello world\n");

    return 0;
}

static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "GOODBYE! world\n");
    printk("1" "whather we ")
}

module_init(hello_world_inti);
module_exit(hello_world_exit);

pr_info("") == printk(KERN_INFO, "sfsd")
pre_warn("") == printk(KERN_WARN, "sfsd")

/*
    static int __init <modulenname>_init(void);
*/