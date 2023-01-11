
Two modes

User mode
kernel Mode

![[Pasted image 20230111091753.png]]

system calls are the only SYNCHRONOUS way to access the kernel

### Kernel Components

- Core Kernel - this code handles the typical core work of any modern operating system, including (user and kernel) process and thread creation/destruction, CPU scheduling, synchronization primitives, signalling, timers, interrupt handling, namespaces, cgroups, module support, crypto and more.

- Memory Management (MM - This handles memory related work, including setup and maintaince of kernel and process Virtual Address Spaces

- VFS - The virtual file system switch is an abstraction layer over the actual filesystem implemented within the linux kernel (inside kernel there is vfat, ext, ntfs etc)
- Block IO: The code paths implementing the actual I/O, from the VFS right down to the block device driver and everything in between, is emcompassed here.
- Network Protocol stack - network protocols at all layers of the model (eg: TCP/IP)
- Inter-Process Communication (IPC) - Linux supports queues, shared memory, semaphores and other IPC mechansims
- Sound Support - All the code that implements audio is here, from the firware  to drivers and codecs
- Virtualization support - Kernal Based Virtual Machines (KVM)


Kernel uses a Monolithic Arch, all kernel components live in and share the kernel address space.

![[Pasted image 20230111110832.png]]

