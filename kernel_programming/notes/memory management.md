
![[Pasted image 20230208115425.png]]


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

