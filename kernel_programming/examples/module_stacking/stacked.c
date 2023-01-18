#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/limits.h>

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("Testing Module stacking");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

#define MODULENAME "minsysinfo"

extern void llkd_sysinfo(void);

static int __init min_sysinfo_init(void)
{
    pr_info("%s: calling sys\n", MODULENAME);
    
    llkd_sysinfo();

    return 0;
}

static void __exit min_sysinfo_exit(void)
{
    pr_info("%s: done\n", MODULENAME);
}

module_init(min_sysinfo_init);
module_exit(min_sysinfo_exit);