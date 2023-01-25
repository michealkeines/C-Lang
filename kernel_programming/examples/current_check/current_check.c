#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h> // current macro
#include <linux/preempt.h> // is_task macro

#define MODENAME "current_check"

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("This is to get current conext");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static inline void show_context(char *nm)
{
    pr_info("%s: %s(): %d ", nm, __func__, __LINE__);

    if (likely(in_task()))
    {
        pr_info(
            "%s: in process context ::\n"
            " name: %s\n"
            " stack start: 0x%px\n", nm, current->comm, current->stack

        );
    } else {
        pr_info(" this is not happenigng");
    }


}

static int __init current_check_init(void)
{
    pr_info("%s: Module has been initialized.", MODENAME);

    show_context(MODENAME);
    return 0;
}


static void __exit current_check_exit(void)
{
    show_context(MODENAME);
    pr_info("%s: Module has been removed.", MODENAME);
}


module_init(current_check_init);
module_exit(current_check_exit);