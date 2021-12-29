A program in execution, process execution must progress in sequential fashion

it includes
program counter,
stack,
heap,
data section,
text - actuall program

process state:

new - the process is being created
running - insturction are being executed
waiting - the process is wating for someeven for occur
ready - ready for running
terminated - exited

process control block (PCB)

the kernel owns this datasturcture

information associated with each process

process state,
program counter,
cpu register,
cpu scheduling info,
memory-mangement info,
account info,
I/O status info

when cpu switchs between process, it swaps the PCB also called as context switching, it adds overhead to the system.

the system save the state of old process and old the saved state for the new process

![[Pasted image 20211222034705.png]]

process scheduling queues:

depending on  the program needs, it can be added to different queues

job queue: set of all processes in the system
ready queue: set of all processes that are ready and waiting to execute
device queue: set of processes waiting for an I/O device

processes migrate among the various queues

![[Pasted image 20211222035504.png]]

Short-term scheduler is invoked very frequently
long-term scheduler is ivoked very infrequently

i/o bound process - spends more time doing i/o than computations, many short CPU bursts

cpu bound process - spend more time doing computations, few very long CPU bursts


a parent can create child processes, which in turn create other processes, forming a tree of processes.

parent and chilren can share all resources like memory space
children can oonly share a subset of parent's resources
parent and child share no resource

execution, parent and chilren can execute concurrently or parent can wait till child finishes

UNIX examples

fork() system call creates a new process

every fork() creates 2^n number of processes

exec() system call used after a fork() to replace the process' memory space with a new program.


everything is a process, we may not see initial process in user mode

scheduler is pid 0, init is pid 1

user mode process goes above 1000 most probably

exit is a system call that is used to tire down the PCB and deallocate resources 

a parent process can teminate the executaion of chilren using abort call

childrens are not allowed to continue if parent is terminated, as it might lead to children not getting dellallocated forever.

cooperatin processes

independent process cannot affect or be affected by the execution of another process

cooperating process can effect or be affected by the exection of another process.

Inter process Communication (IPC)

Mechanism for processes to communicate and to synchronize their actions

IPC operations

send(message) - message size fixed or variable
receive(message)

if P and Q wish to communicate, they need to,
- establish a communication link between them
- exchange messages via send/receive

Implementation of communication link
- Physical (shared memroy, bus)
- Logical (Ds to point to a location that could be used)

Synchronization

message passing may either blocking or non-blocking

blocking is considered synchronous

blocking send has the sender block until the message is received
blocking receive has the receiver block until the message is available

non-blocking is considered asynchronous

non-blocking send has the sender send the message and continue
non-blocking receive has the receiver recieve a valid message or null

Buffereing

queue of messages attached to the link

zero zapacity - 0messages
sender must wait for receiver

bounded capacity - finite length of n messages 
sender must wait if link full

unbounded capacity - infinite length
sender never waits




