
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

DIrect mapping

direct mapping of RAM to the kernel segment starting at PAGE_OFFSET

the physical ram is directly mapped into the kernel segement using one to one page frame mapping

page 0 in physical frame will be mapped tinto virtual page 0 and so on

if we know the addres sof the page 0, we can calculate the relative address of any opage it will be same blocks away for both physical and virtual

![[Pasted image 20230225014442.png]]

as the physical address starts from 0x00000000, we could just add or subttract to get the KVA and PA


to get Physical address if KVA was given, we just have subtract PAGE_OFFSET from that


PA =  KVA - PAGE_OFFSET

=> 0xc0000003 + 0xc00000000
=> 0x3



to get KVA if PA was given, we just add PAGE_OFFSET to that

KVA = PAGE_OFFSET + PA

=> 0xc0000000 + 0x3
=> 0xc0000003




https://stackoverflow.com/questions/36639607/how-exactly-do-kernel-virtual-addresses-get-translated-to-physical-ram

When the kernel starts it creates a single page table for itself (swapper_pg_dir) which just describes the kernel portion of the virtual address space and with no mappings for the user portion of the address space. Then every time a user process is created a new page table will be generated for that process, the portion which describes kernel memory will be the same in each of these page tables. This could be done by copying all of the relevant portion of swapper_pg_dir, but because page tables are normally a tree structures, the kernel is frequently able to graft the portion of the tree which describes the kernel address space from swapper_pg_dir into the page tables for each user process by just copying a few entries in the upper layer of the page table structure. As well as being more efficient in memory (and possibly cache) usage, it makes it easier to keep the mappings consistent. This is one of the reasons why the split between kernel and user virtual address spaces can only occur at certain addresses


Part 1: Are kernel virtual addresses really translated by the TLB/MMU?

Yes.

Part 2: How is swapper_pg_dir "attached" to a user mode process.

All page tables (whether swapper_pg_dir or those for user processes) have the same mappings for the portion used for kernel virtual addresses. So as the kernel context switches between user processes, changing the current page table, the mappings for the kernel portion of the address space remain the same.


some of the kernel datastructures like task_struct, stasck_buff for IP, these are allocated a lot and having a separate cache for this particular data structures improves the overall perfoormance

this method is called slab cache

/proc/slabinfo

to get the total memory used by slab cache, we /proc/meminfo

main routines are in slab.h

kmalloc, kzalloc

in kmalloc we get a pointer to top of te new buf, and the data within it may be ranodm
in kzalloc, we get a pointer to top of the new bug and the data will be zeros

we use kfree to dellocate tmemroy that is allcoated using kmalloc or kzalloc

for security reasons, we shoudl make sure ,we are zeroring out the buffer before freeing that address

freeing as sson as an memset with zeors may not be the right solution against info leask as the compiler migght try to  optimize that step my not set setting anytiing in the memset operation and just freeing that meory


we can use vmstat -m to get the info about available slab memory

kmalloc-rcl version are used like anti-fragmentation measure, tht it is reclaimable

slab cache iteself can only allocate memeory max of 8kb per call

high values are moved to page allocator


we have device resource manager API, eg: devm_kmalloc, this is excatly like normal kmalloc, it is jsut hte developer doest have to free the memory, when the work is over, this manger itself will free those memory when the dirver is plugged off, or removed or if the deriverr is removed from the kernel using rmmod

the first agument for this api, is a devie struct, that is meta date for the physical device, so it gets a relation with allocate memory => device

if the needed memory is low, use slab allocator, if the neede memory is an order of2 then use page allocator

if we allocate memory using kmalloc lets say 20byte, sizeof will give us 20byts, ksizre will give 32 bytes, becuase the total memory allocated by kmalloc for 20bytes willbe 32 bytes

![[Pasted image 20230309111753.png]]

three different implemenation of slab allocator inside kernel

SLAB - under optiomized
SLUB - unqueued allocator
SLOB - simplified version (doesnt work on large systems)


we can create custome slab cache for our custome data structures in our kernel modules


kmem_cache_create - to create the cache memeory, return the mem address
kmem_cache_alloc - takes memory address of cache and return the obj address
kmem_cache_free - take memory address of cache and address of obj that needs to be removed

kmem_cache_destroy - removes the allocated cache memory

we can use vmstat to check the number of allocations for our custom struct

```
sudo vmstat -m | grep custo
```


in general there might be a lot of custom caches allocated, whenn there is need for memory, the kernel is inteligent enought to deallocate caches to free up some memory

this process is called slab shrinking

and it is done like, when we register a custom cache, we can also register in shrinker api, so that the kernel can call this when it needs space

we just use register_skrinker with one paramter, that has to callback

count_object - counts the number of freeable object that are preallocated
scan_object - this free those freable objects.


Debugging techinques for slab cache

slab poisiong using SLAB_POSION

```c
custom_cache_loc = kmem_cache_create(

CACHENAME,

sizeof(struct custom_struct),

sizeof(long),

SLAB_POISON | SLAB_RED_ZONE | SLAB_HWCACHE_ALIGN,

c_func

);
```

this means, whenever the something is allocated wihtin this cache, iit will be filled with an ranodm pattern of some ascii chat

``
```
#define POISON_INUSE    0x5a    /* for use-uninitialized poisoning */
#define POISON_FREE     0x6b    /* for use-after-free poisoning */

#define POISON_END      0xa5    /* end-byte of poisoning */
```

when we allocate something we set it to 0x5a
when we free an used memory we set it to 0x6b

the last byte will be set to 0xa5, if someoone writes over this address, we can detect the overrflow


![[Pasted image 20230316120029.png]]



Vmalloc doesnt grantee phyically contigenous pages

vmalloc is usefull when you need buf of size greater than 4mb and if youre in porcess context

