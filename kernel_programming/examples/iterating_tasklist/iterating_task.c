#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kallsyms.h>

#define MODNAME "iterating_task"
#define MAXLEN 128

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("get all threads related to a proces");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.2");

static int get_all_process(void)
{
    struct task_struct *p;

    char tmp[MAXLEN];

    int numread = 0;
    int n = 0;
    int total = 0;

    char first_line[] = "   Name    |   TGID    |   PID |   RUID    |   EUID    ";
    pr_info("%s\n", first_line);
    rcu_read_lock();

    for_each_process(p) {
        memset(tmp, 0, 128);
        n = snprintf(tmp, 128, "%-16s|%8d|%8d|%7u|%7u\n", p->comm, p->tgid, p->pid, 
            __kuid_val(p->cred->uid), __kuid_val(p->cred->euid)
        );

        numread += n;
        pr_info("%s", tmp);
        cond_resched(); // give up timeslice, that is to deschedule or give up the cpu
        total++;
    }

    rcu_read_unlock();

    return total;
}

static int __init process_iterate_init(void)
{
    int total;

    pr_info("%s: Inserted\n", MODNAME);

    total = get_all_process();

    pr_info("%s: totaol # of processes: %d\n", MODNAME, total);

    return 0;
}

static void __exit process_iterate_exit(void)
{
    pr_info("%s: Removed\n", MODNAME);
}

module_init(process_iterate_init);
module_exit(process_iterate_exit);