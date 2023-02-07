#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/sched/signal.h>


#define MODNAME "iterating_threads"

MODULE_AUTHOR("Micheal keines");
MODULE_DESCRIPTION("Iterate over threads spawned by a parent");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static inline void display_idle_thread(void)
{
    struct task_struct *t = &init_task;

    pr_info("%8d %8d 0x%px 0x%px [%16s]\n",
        t->pid,
        t->pid,
        t,
        t->stack,
        t->comm
    );
}

static int show_thread(void)
{
    struct task_struct *g = NULL;
    struct task_struct *t = NULL;

    int nr_thrds = 1, total = 1;

    char buf[256], tmp[128];

    const char header[] = "TGID     |       PID         |       current"
    "       |           stack-start     |       thread-name         |           MT threads\n";

    display_idle_thread();

    rcu_read_lock();

    do_each_thread(g, t) {
        task_lock(t);

        snprintf(buf, 255, "%8d %8d", g->tgid, t->pid);

        snprintf(tmp, 127, " 0x%px", t);

        snprintf(buf, 255, "%s %s 0x%px", buf, tmp, t->stack);

        if (!g->mm) {
            snprintf(tmp, 127, " [%16s]", t->comm);
        } else {
            snprintf(tmp, 127, " %16s", t->comm);
        }

        snprintf(buf, 255, "%s%s", buf, tmp);

        nr_thrds = get_nr_threads(g);

        if (g->mm && (g->tgid == t->pid) && (nr_thrds > 1)) {
            snprintf(tmp, 127, " %3d", nr_thrds);
            snprintf(buf, 255, "%s%s", buf, tmp);
        }
        
        snprintf(buf, 255, "%s\n", buf);
        pr_info("%s", buf);

        total++;
        memset(buf, 0, sizeof(buf));
        memset(tmp, 0, sizeof(tmp));

        task_unlock(t);

    } while_each_thread(g, t);

    rcu_read_unlock();

    return total;
}

static int __init iterate_threads_init(void)
{
    pr_info("%s: Inserted", MODNAME);

    int total;

    total = show_thread();

    pr_info("%s: total number of threads: %d\n", total);

    return 0;
}

static void __exit iterate_threads_exit(void)
{
    pr_info("%s: Removed", MODNAME);
}

module_init(iterate_threads_init);
module_exit(iterate_threads_exit);