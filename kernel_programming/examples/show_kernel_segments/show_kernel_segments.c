#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/version.h>
#include <asm/pgtable.h>
#include <asm/fixmap.h>

#define MODNAME "show_kernel_segments"

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("show kernel segments");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static int show_user_vas;

module_param(show_user_vas, int, 0600);

static void print_kernel_segments(void)
{

}

static int __init show_kernel_segment_init(void)
{
    pr_info("%s: Inserting");

    print_kernel_segments();

    pr_infor("done printing");

    return 0;
}

static void __exit show_kernel_segment_exit(void)
{
    pr_info("%s: Exiting", MODNAME);
}

module_init(show_kernel_segment_init);
module_exit(show_kernel_segment_exit);
