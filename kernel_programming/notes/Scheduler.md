
This person is responsiblle for sharing the CPU time properly among all waiting threads. 

CPU performance is usually expressed in Millions of Instructions Per Second (MIPS), which can also be expressed as a given amount of instructions attainable per Hz, 
leading to  

```
capacity(cpu) = work_per_hz(cpu) * max_freq(cpu)
```


![[Pasted image 20230409025003.png]]


Preemptive Multitasking - the schedular decides when a process is to cease running and a new process is to begin running. The action of involuntarily suspending a running process is called preemption

Cooperative Multitasking - a process does not stop running untill it voluntaryly decides to do so. the act of a process voluntariy suspending itself is called yeilding.

time slice - the time a process runs before it is gets preempted

I/O bound - it only runs short ime as it will eventually wait for one or more I/O to be completed

Processor bound - it is not blocked by any I/O, thus will run untill it get preempted by a higher priority process or run out of tiime slice

Process Priority:

Nice value: a number from -20 to +19 with default as zero, larger nice value corresponds to lower priority

Real-time priority: default range from 0-99. Higher real-time priority values corresponds to greater priority.

real time processes are at a higher priority than normal processes

both nice value and real-time priority is saved togeterh in prio field of task struct

![[Pasted image 20230409031403.png]]

in reality, 

0 - 99 will be the real-time priority, higher values gets more priority, 99 highest

100 - 139 will be the nice value, small value get higher priority, 100 highest

```
https://stackoverflow.com/questions/8887531/which-real-time-priority-is-the-highest-priority-in-linux

99 will be the winner for real time priority.

PR is the priority level (range -100 to 39). The lower the PR, the higher the priority of the process will be.

PR is calculated as follows:

    for normal processes: PR = 20 + NI (NI is nice and ranges from -20 to 19)
    for real time processes: PR = - 1 - real_time_priority (real_time_priority ranges from 1 to 99)

```



