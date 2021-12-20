Address space:

- a group of memory addresses usable by something
- Each program (process) and kernal has potentially different address space

Address Translation:

- Translate from virtual addressess (emitted by CPU) into Physical Addresses (of memory)
- Mapping often performed in Hardware by memory management unit (MMU)


![[Pasted image 20211207234432.png]]

This mapping makes sure that no process can read or write some other processes memeory in anyway.

![[Pasted image 20211208000551.png]]

but what if the process tries to modify the mapping mechanism itself, thus making the mapper to overwrite same memory?

This is taken care using Dual Mode Operation:

Hardware provides at least two modes

- Kernel Mode ( Privileged or super user mode)
- User Mode ( application programs )

Some privileges instructions/operations are prohibited in user mode

eg: User mode process cannot modify page tables ( mapper form the above image )

But then we may need some valid operation from user mode mode thatt will require more privilege.

This is solved by the system call architecture, system calls are API that are has most important privleged functionalities that can be called directly from the user mode.

![[Pasted image 20211208002210.png]]

The user process traps into kernel  mode executing the system call and then brought back to the user mode.


Address Translation and Dual mode allows us to secure the physical memory between processess.


