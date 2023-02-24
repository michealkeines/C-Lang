
![[Pasted image 20230208115425.png]]

one meory address will allways store 8 bits that is 1byte 

in 32 bit arch, we can ask for 4bytes at a time - that is the bus size
in 64 bit arch, we can ask for 8bytes at a time - that iis the bus isze

u:k

32 bit - 2:2

configuring the VM split is not directly posssible for 64 bit archs

in 64 bit, currently most kernel only use 48 bits of address space


64 biti arch

kernel address will have 16 most sign bits set to 1
user address will have 16 most sign bits set to 0

kernal - 0xffff .....
user - 0x0000 .....

![[Pasted image 20230213104139.png]]

![[Pasted image 20230213104323.png]]

![[Pasted image 20230213104525.png]]

/proc fs is one of the best ways to examine vas and other files

![[Pasted image 20230213111218.png]]



```
start address - end address, 
7f3b0d2b1000-7f3b0d2b3000 rw-p 00032000 08:01 2893770                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2


r - read
w - write
x - executable
[p, s] - private or shared

00032000 - is the offset that is getting mapped for this particular lib file (/usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)

08:01 - is of the form mj:mn, where mj is the major number and mn is the minor number of the device file where the image reside, it is only valid if there is a valid file that is getting mapped

2893770 - inode key, we can use `ls -i` to get the inode key of any file


path - is just he path of teh file tha tis gettig mapped






```


/proc/pid/smaps to get more infor into the memory segments

VMA is kernel data structure, it gets mapped to very segment within a VAS

this only applies for user VAS

for kernel virtual address space there is not VMA

red-black data strcture tree is used to hold VMAs

task_struct holds this head pointer for process 

current->mm->mmap


when we use cat /proc/pid/maps, the code just interates over the processes VMAs and only print out important info

kernel address space is divided usign a PAGE_OFFSET, and it divides the direct mapings and viruall memory

below PAGE_OFFSET is low mem and above is high mem

direct mappes are directly mapped to the phyical address, so these are called kernel logical address, that it that at fixed offset

the direct mapping is equal the total physical memory size

if the memory is too big, the rest of the physical memory is dirrectly mapped into ZONE_HIGHMEM

high_memory inside the lowmemory region is mapped to a tempory location and get swapped?

Variables and Macros

Vector table - holding an array of function pointer that could handler different interrupts

VECTORS_BASE = start of the kernel vector table

FIXADDR_START = start of the kernel fixmap region

MODULES_VADDR = start of the kernel modules region

MODULES_END = size of the kernel modules region

KASAN_SHADOW_START = start of KASAN region

KASAN_SHADOW_END = size of KASAN region

PAGE_OFFSET = represents the start of the lowmem region

high_memory = upper bound of direct mapped memory

`_text _etect` start and end of kernel text region

`__init_begin, __init_end` start and end of kernel init section

`_sdata. _edata` start and end of static data region

`__bss_start, __bss_stop` start and end of kernel BSS region, that is uninitiialized data

![[Pasted image 20230216100827.png]]


NULL trap page it has no permission set and any access to memory 0x000000 will be refering to this address, it triggers a fault handler which then passes SIGSIGV to the process that deferenced this address

this is also called NULL pOINTER dereference

![[Pasted image 20230223104436.png]]

Address randomization

settiing this using proc file system

![[Pasted image 20230223110122.png]]

```
0 	(User mode) ASLR turned OFF; or can be turned off by passing the kernel parameter norandmaps at boot.
1 	(User mode) ASLR is ON: mmap(2) based allocations, the stack, and the vDSO page is randomized. It also implies that shared library load locations and shared memory segments are randomized.
2 	(User mode) ASLR is ON: all of the preceding (value 1) plus the heap location is randomized (since 2.6.25); this is the OS value by default.
```

## Physical Memory

It is like tree like hierachy consisting of node, zones, and page frames

Nodes are divided into zone and zone consist of page frames

A Node abstracts  a physical bank of ram which is associated with one or more cpu cores

Nodes:

nodes are data structures used to denote a physical RAM modules onthe system

it si pg_data_t this is the structure used forr holding information about phyical ram

this is like actual hardware is being is abstracted via software metadata

Non-Uniform Memory Access NUMA - where the core on which a kernel allocaiitn request ocurs does matter (memory is treated non  uniiformatly)

Unform Memory access UMA - where the core on which kernel allocation request occurs dosnt matter. (memory iis treated uniformaly)



NUMA arch always has more two cores and more physical ram, that way every core gets separate memory allocation, it assures that the memory allocation will consider the nearset possible Node in the physiclal memory



If there are two or more nodes, it is a true  NUMA system and if only one node, then it is a fake NUMA 

example:

A total of 32 CPU cores (as seen by the OS) within two physical sockets (P#0 and P#1) on the motherboard. Each socket consists of a package of 8x2 CPU cores (8x2, as there are actually 8 physical cores each of which is hyperthreaded; the OS sees even the hyperthreaded cores as usable cores).
A total of 32 GB of RAM split up into four physical banks of 8 GB each

![[Pasted image 20230224102604.png]]


A thread running some kernel or device code in process context, on CPU core #18, lets say it requests for some ram, now the kernel MM layer, understanding NUMA, will have the request servered from any free page fream in any zones on NUMA node 2 as it is the closest  to the processor code that the request is issued upon.


just in case there is no page free frames in any zone within this NUMA node 2, the kernel will go accross the interconnect and request RAM page frames form another node zone

Zones

![[Pasted image 20230224103909.png]]

The number of zones per node is dynamically determined by the kernel at boot.


/proc/buddyinfo can used to view the node of node and zone and available page frames in the particular ram

the kernel data structure that is related to zone is struct zone

