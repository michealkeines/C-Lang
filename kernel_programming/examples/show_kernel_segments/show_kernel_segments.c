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
#include "conv.h"

#define MODNAME "show_kernel_segments"
#define ELLPS "|                           [ . . . ]                         |\n"

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("show kernel segments");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static int show_user_vas;

module_param(show_user_vas, int, 0600);

static void print_kernel_segments(void)
{   
    pr_info(ELLPS "| fixmax region: " "%px - %px  " "[%4ld MB]\n");

#if (BITS_PER_LONG == 64)
    pr_info("|module region:       "
        "  %px - %px        |  [%ld MB]\n",
        SHOW_DELTA_M(MODULES_VADDR, MODULES_END)
    );
#endif
    
    pr_info("|vmalloc region:         "
        " %px  - %px   |  [%4ld MB = %2ld GB]\n",
        SHOW_DELTA_MG(VMALLOC_START, VMALLOC_END)
    );

    pr_info("|lowmem region:       "
        " %px - %px | [%4ld MB = %2ld GP]\n",
        SHOW_DELTA_MG((unsigned long) PAGE_OFFSET, (unsigned long) high_memory)
    );
}


static void print_user_segments(void)
{
    pr_info("+------------ Above is kernel-seg; below, user VAS  ----------+\n"
            ELLPS
            "|Process environment "
            " %px - %px     | [ %4zd bytes]\n"
            "|          arguments "
            " %px - %px     | [ %4zd bytes]\n"
            "|        stack start  %px\n"
            "|       heap segment "
            " %px - %px     | [ %4zd KB]\n"
            "|static data segment "
            " %px - %px     | [ %4zd bytes]\n"
            "|       text segment "
            " %px - %px     | [ %4zd KB]\n"
            ELLPS
            "+-------------------------------------------------------------+\n",
            SHOW_DELTA_b(current->mm->env_start, current->mm->env_end),
            SHOW_DELTA_b(current->mm->arg_start, current->mm->arg_end),
            current->mm->start_stack,
            SHOW_DELTA_K(current->mm->start_brk, current->mm->brk),
            SHOW_DELTA_b(current->mm->start_data, current->mm->end_data),
            SHOW_DELTA_K(current->mm->start_code, current->mm->end_code)
            );
}

static int __init show_kernel_segment_init(void)
{
    pr_info("%s: Inserting");
    pr_info("%s: reporting kernel segments", MODNAME);
    print_kernel_segments();

    if (show_user_vas)
    {
        pr_info("%s: reporting user segments", MODNAME);
        print_user_segments();
    }

    pr_info("done printing");

    return 0;
}

static void __exit show_kernel_segment_exit(void)
{
    pr_info("%s: Exiting", MODNAME);
}

module_init(show_kernel_segment_init);
module_exit(show_kernel_segment_exit);
