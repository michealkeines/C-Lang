
# Kernel Schedulable Entity

KSE - 

scdeduling is performed in the thread level not in the process level

hardware interrupts always have the higest priority

we can use pref tool to find which task is running on which core, in a given moment

![[Pasted image 20230405121455.png]]

we have 5 scheduler classes in priority order

stop-schedule,
deadline,
real time,
fair,
idle

there 5 classes inherit or abstracts over sched_class

the scheduling policy will be held by 
task_struct->policy = (FIFO, RR, OTHER)
task_sched_class = (deadline, real time, fair , idle)

there is runqueue every schdule class per cpu

![[Pasted image 20230405123243.png]]


if there is 8 cpus and 5 sched class, then there will 40 run quues

1 cpu will have 5 runqueues

8 cpu will have 8 x 5 run queues



if no one wants to run on the cpu, we have idle therad that will  alwasy say yes, when asked to be scheduled

![[Pasted image 20230405123925.png]]


within task_struct we have this field called sched_entity, which holds vruntime, its the coutner value for the amoutn of time the thread used the processor

in CFS sche algorithm, we use a red-black tree, and threads are added to it based on the vruntime value, 

so the next value to be popped of for running will be the left most node (minium runtime), but the traversal to the left-most node will be o(log n) operation, but with some clearn optimization and cache, we can get the left most node in o(1) time, taht is just one operation


we can use chrt commmand to query and get the current scheduling policy of any pid

the flag TIF_NEED_RESCHED is updated

when a timer irruput occurs 

when there is another process wiht less time slice than can current (this is handled in the current scheduled class itself, if it reaches this condition, it will call a callback function that wwill set the need flag)

the flag i read in two points

when ever we are get back from a system call or intruppt call

so the flag is set by some one and read at particular points

Preemption points, on the other hand, are specific points in the kernel code where the scheduler can preempt a running thread and switch to another thread of higher priority. These points are usually placed in code that can block or run for an extended period of time, as these are situations where preemption is most beneficial.

Preemption points are a way to ensure that the scheduler can preempt a running thread even if a scheduler opportunity does not naturally occur. By placing preemption points throughout the kernel code, the scheduler can interrupt a running thread at the next preemption point and switch to a higher priority thread if one is available.


```
 * __schedule() is the main scheduler function.
 * The main means of driving the scheduler and thus entering this function are:
 * 1. Explicit blocking: mutex, semaphore, waitqueue, etc.
 *
 * 2. TIF_NEED_RESCHED flag is checked on interrupt and user space return
 *    paths. For example, see arch/x86/entry_64.S.
 *
 *    To drive preemption between tasks, the scheduler sets the flag in timer
 *    interrupt handler scheduler_tick().
 *
 * 3. Wakeups don't really cause entry into schedule(). They add a
 *    task to the run-queue and that's it.
 *
 *    Now, if the new task added to the run-queue preempts the current
 *    task, then the wakeup sets TIF_NEED_RESCHED and schedule() gets
 *    called on the nearest possible occasion:
 *    - If the kernel is preemptible (CONFIG_PREEMPTION=y):
 *
 *    - in syscall or exception context, at the next outmost
 *      preempt_enable(). (this might be as soon as the wake_up()'s
 *      spin_unlock()!)
 *
 *    - in IRQ context, return from interrupt-handler to
 *      preemptible context
 *
 *    - If the kernel is not preemptible (CONFIG_PREEMPTION is not set)
 *      then at the next:
 *       - cond_resched() call
 *       - explicit schedule() call
 *       - return from syscall or exception to user-space
 *       - return from interrupt-handler to user-space
 * WARNING: must be called with preemption disabled!
```

