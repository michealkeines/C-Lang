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
    pr_emerg ("Hello, world @ log-level KERN_EMERG   [0]\n");
    pr_alert ("Hello, world @ log-level KERN_ALERT   [1]\n");
    pr_crit  ("Hello, world @ log-level KERN_CRIT    [2]\n");
    pr_err   ("Hello, world @ log-level KERN_ERR     [3]\n");
    pr_warn  ("Hello, world @ log-level KERN_WARNING [4]\n");
    pr_notice("Hello, world @ log-level KERN_NOTICE  [5]\n");
    pr_info  ("Hello, world @ log-level KERN_INFO    [6]\n");
    pr_debug ("Hello, world @ log-level KERN_DEBUG   [7]\n");
    return 0;
}

static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "GOODBYE! world\n");
}

module_init(hello_world_inti);
module_exit(hello_world_exit);

/*
    static int __init <modulenname>_init(void);
*/