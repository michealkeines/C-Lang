#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("Micheal");
MODULE_DESCRIPTION("This is to test parameters");
MODULE_VERSION("1.2.2");
MODULE_LICENSE("GPL");

static int debug_mode;

module_param(
    debug_mode,
    int,
    0600 
);

// 4,2,1 => 7, 

// w and r = 6 for current user and 0 for rest 
// that how we got 600
module_param_named(new_debug_mode, debug_mode, int, 0600);


static int __init param_pass_init(void)
{
    pr_info("para pass has be added");
    pr_info("debug mode: %d", debug_mode);
    if (debug_mode) {
        pr_info("debug mode enabled");
    }
    pr_info("crossed ");
    int what = 0;
    while (debug_mode) {
        what = 1;
        pr_info("printing");
    }
    pr_info("crossed because of debugmode updated value");
    pr_info("updated value: %d", debug_mode);
    return 0;
}

static void __exit param_pass_exit(void)
{
    pr_info("para pass has be removed");
}

module_init(param_pass_init);
module_exit(param_pass_exit);