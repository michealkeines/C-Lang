Thread of execution:

Independent Fetch/decode/execute loop operating in some address space.

Execution sequence:

- Fetch Instruction at PC
- Decode
- Execute (possibly using registers)
- write results to registers/memory
- PC (next instruction)
- Repeat

Each virtual CPU needs a sturcture to hold
program counter, stack pointer, register

how to switch from one CPU to the next?
save the PC, SP and registers in current state block
load the PC, SP and registers of new state block

  what triggers the switch?
  timer, interepts, I/O, voluntery yield
  
  consequence of sharing:
  
  -each thread can access the data of every other thread
  -threads can share instructions
  
  This could be done physically by using simultanious multithreading(SMT) or Hyper threading(intel)
  
  
  based on the number of physical hyperthreads, we can load threads intro process
  
  intel i7 7th gen has 16 hyperthread space, we can run 16 threads without switching overhead, as switching will be instantious
  
  
how to protect threads from one another?

Protection of memory
- every task does not have access to all memory

Protection of I/O devices
- every task does not have access to every device

Protection of access to processor
- use of timer
- must not be possible to disable timer from usercode

Address space => the set of accessible address 

when we try to write to a unallocated space we get segmentation fault


 Process: a single, sequential stream of execution in its own address space
 
 often called as heavy weight process
 
 Process control Block
 
 the current state of process held in PCB
 
 process state,
 process number
 program counter,
 registers
 memory limtis
 list of open files
 
 only one PCB active at a time.
 
 
  
  deciding which process to give the CPU control is called scheduling
  
  we are switching context from one process to another process
 
![[Pasted image 20211220083014.png]]

new - the process is being created
ready - the process is waiting to run
running - instructions are being executed
waiting - process waiting for some event to occure
terminated - the process has finished execution

![[Pasted image 20211220083415.png]]



what does it take to create a process?

construct new PCB, inexpensive

setup new page tables for address space, expensive

unix fork(), the child process gets a complete copy of the parent memory and I/O state, expensive

is process equal to program?

a program is just part of the process state

a program can invoke many processes

to make two processes talk, we give them shared memory by mapping same memory all processes (IPC)

threads are called light weight process, that a process can have many threads all share the same address space.

only thing that is private for thread in a process it its own PCB(stack, registers)

no protection of memory between threads

