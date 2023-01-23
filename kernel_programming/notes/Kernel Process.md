
In general a user space process asks the kernel to give set the privilege bit for the particular thread or process, so it could run kernel code, this is called a process context

incase if an intruppt occurs and there is no userspace process related to it, the respective intreupt handler will be ran under intruppt context

the mapping of intruppts to particular method is called interupt service routine ISR

![[Pasted image 20230123112528.png]]


so every process atleast has one thread, where it calls the main method of hte executable

the kernel scheduler doesnt know about the processes, it only knows about the avialble threads

every thrread is mapped to kernel datastructure called task structure or also called process discriptor

every user space thread has its own stack for all privileged level, so it will have two stacks
user stack and kernel stack

kernel thread will only have one stack, as the will never execute in user space

![[Pasted image 20230123114203.png]]

