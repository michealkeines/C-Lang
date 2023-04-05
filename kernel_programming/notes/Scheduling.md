
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
