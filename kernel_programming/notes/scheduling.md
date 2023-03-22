
the main objective of the scheduling system is to keep the CPU busy at all time

there are different policies that is followed to swap in and out processes from the CPU

these policies can be conflicting, and everytime the scheduler steps in to swap a process from the CPU, the schedular itself uses the CPU, which means we are not doing any work at that time.


every device will have its own queue, if a process is waiting for the device, it will be added to that queue


three different batches

long-term scheduler - this itself take times to schedules the processes

short-term scheduler - goes in scheduels and gets our as soon as possible like in  100 millisecs

medium term scheduler - it take some time and tries to schedule the small jobs first

