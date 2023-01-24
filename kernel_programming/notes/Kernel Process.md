
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

within kernel code we shouldnt get a page fault this is acheive by using a static kerenel stack, tthat way we konw for sure that when we enter into kernel context, our pages will  alos be paged

kernel static is of fixed size that is 2k in 32bit arch and 4k in 64 arch

in x86 and arm if a hardware intrupppt occurs, the kernel is create an intruppt stack which will hold the intruupt handler method

to view kernel stack of pid, we hae fd that is mapped in /proc

![[Pasted image 20230124092422.png]]

bottom to top, entry will be botom and do_sys will be the top frame, that is current function that isgetting executed

this is just the kernel stack of proces

to view the stack of an user mode proces, we could jsut attack to the pid using gdb, 

`thread apply all bt`

