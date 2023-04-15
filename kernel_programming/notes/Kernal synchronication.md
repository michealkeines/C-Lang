
Critical section

when a code is considered to be in a critical section, it has to either run exclusively or without interruptiion

atomic operations are indivisable eg: system call, dont really get scheduled off as they are atomic in nature

there are two things that are completely attomic

that is

-> single machine language instrucion

mov rbp, rsp

-> read/writes from memory using bus, that is typicllay as big as the arch bit, in 64 bit arch, reading a u64 vlaue willbe atomiic

![[Pasted image 20230413122249.png]]

rules


    (Always) Exclusively: Alone (serialized)
    (When in an atomic context) Atomically: Indivisibly, to completion, without interruption


as we only only two things are completly atomic

how to we make few lines of c code atomic?

in user space:

by settin shedule policy to real-tim pro 99, that way only hardware interrupts can preumpt the thread

in kernel space:

possible data races:

multi process concurrency - in this case there are multiple cores, so two cores might execute the same code, casuing race

premptable kernel - in this case the kernel can preempt p1 while it was reading some global var and p2 was scheduled which going to  write to same global var casuing race

Hardware interrupts - if p1 is running, and a hard irq occurs, it will tkae the cpu, leave the p1 hanging, and we may not know if p1 will be scheduled next


deadlocks:

self deadlock - same thread trying to acquire the lock twice

two or more locks - p1 accquires A and wait for B, P2 accquires B and waits for A

complex - if a inturrpt handler want lock A and accquires it in core 1 and same intrrupt occurs on core 2 and it waits for lock A

livelocks:

A real-world example of livelock occurs when two people make a telephone call to each other and both find the line is busy. Both gentlemen decide to hang up and attempt to call after the same time interval. Thus, in the next retry too, they ended up in the same situation. This is an example of a live lock as this can go on forever.

Priority inversion

when a high priority thread is prempted with low priority thread as the low priority thread has a lock over a resource that is needed by the high priority thread

types of locks

mutex
spin

in both the case, the threading try to get the lock and the winner get into critical secion and other have to wait till they get unlock

the waiting manner is the difference

in mutex lock, the thread that didnt accquire lock will be put to sleep and wake up when the unlock is triggered by kernel

try lock -> sleep else locked -> do something -> unlock

in spin lock, the threads that didnt accquire lock will keep try to poll for unlock untill it gets unlocked, this comes in handy in mutli core systems to keep the cpu with some optimized run

while (try lock) -> do something -> unlock

which on to choose, as mutex lock has the overhead of going to sleep and then getting rescheudled

in spin lock we have CPU slice as long the wait time is under our cpu time slice

, in conclusion, for short non-blocking critical sections, using a spinlock is (far) superior to using a mutex lock.


also we cannot use mutax lock inside interrupt context


there is two type so sleep

interruptable sleep 
uninterruptable sleep

mutax_lock uses uniterruptable sleep and it wont be distruped by any interrupts or soft signal

but if we wnat to it be intruptabel then 

we can use mutex_lock_interruptible



semaphore

it is also lock and unlock resouce

but semphore signals the receivers that some event happened

    A single consumer enters its critical section. Since fullCount is 0, the consumer blocks.
    Several producers enter the producer critical section. No more than N producers may enter their critical section due to emptyCount constraining their entry.
    The producers, one at a time, gain access to the queue through useQueue and deposit items in the queue.
    Once the first producer exits its critical section, fullCount is incremented, allowing one consumer to enter its critical section.

when using spin_llockk_irq, we diable hardware intruppts in the particular core, and restore it have all when left out of section

when if some else had send some value there ,ti wilil be earsed and set to full in the end, this was fixed by saving the state and restoring it later

```

    Simplest, lowest overhead: Use the non-irq spinlock primitives, spin_lock()/spin_unlock(), when protecting critical sections in the process context (there's either no interrupts to deal with or there are interrupts, but we do not race with them at all; in effect, use this when interrupts don't come into play or don't matter).
    
    Medium overhead: Use the irq-disabling (as well as kernel preemption disabling) versions, spin_lock_irq() / spin_unlock_irq(), when interrupts are in play and do matter (the process and interrupt contexts can "race"; that is, they share global data).
    
    Strongest (relatively), high overhead: This is the safest way to use a spinlock. It does the same as the medium overhead, except it performs a save-and-restore on the interrupt mask via the spin_lock_irqsave() / spin_unlock_irqrestore() pair, so as to guarantee that the previous interrupt mask settings aren't inadvertently overwritten, which could happen with the previous case.

```


we can use atomic_t and refcount_t to store integers and get api that increment, decrements, sets value in proper manner, without us having to write the lock for variables

accessing hard ware registers is also an global operation that need critical session kernel provided RMW api to do those in safe manner

we also reader-writer lock, if there is no write, many readers can acquire the lock but only on write at a time



false  sharing happens when two different thread uses the same data structure that could place in same cache

![[Pasted image 20230415085121.png]]

this wway cpu0 invalidtes the access done by cpu1 and visa version, but decreasing the performance



PerCPU variables allows us to make a copy of an variable per CPU thus removing the need for using lock to stop other cores from using this



lockdep can be used find locks based issues and to make sure that any ordering cant lead to dealock with 100% accuracy

similar to volatile keyword that grantunee that no optimzations are done in variable

memeory barieers are used make sure the path or ordering of read/write dont get optimized of check properly

