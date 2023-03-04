
there is two primary optiions

Page Allocator or Buddy sytem allocator (algorithm is called as buddy system)

slab allocator/slab cache, the latest kernel is using unqueued slab allocator


page allocator is the base engine for allocation/deallocation

a slab allocator is layer upon the page allocator

![[Pasted image 20230228122621.png]]


the page allocator keeps track of the free physical frames in freelist data struccture

the freelist is a doubly circular linked list

we  start at head and end at head, we have pointer to both front and back

the total lenght of this list could be of MAX_ORDER -1 

MAX_ORDER is arch dependent in x86 it is 11, we can store 10, 2 power max_order 

![[Pasted image 20230228123720.png]]



in this linked list, 
the first pointer points to a 4k of contingnous memory
the second pointer points to a 8k of contingonous memory
the final pointer pointst ot a 4mb of memory

there is no limit in the number of chucks that could be added to the order

the only rule is if we are adding a chuck to the order 0, it has to be of  size  4k  htat   is the only rule

if     we wer e   tto add it to he seond oorrder ,,  then the addded chunk shhhoooould  of size   two pages or 8 kb



![[Pasted image 20230228124025.png]]



if we allocote left 1 kb, we dequeue 1kb from 0th index, and when deallocation, we enqueue it back to that pointer

we can look at this list using /proc/buddyinfo

![[Pasted image 20230228125005.png]]

so in node 0 zone DMA32, in order 0 we have 3173 4kb free chunks
in node 0 zone DMA, in order 3 we have 37 32kb free chunks



![[Pasted image 20230228124922.png]]
every zone has its own order of free lists

so if we wan to allocate 4kb of memory,
 it is just 1 page, so we look at order 0 and see if here is any free chunks, if yes, we dequeue one from this l queue and upadte the total

aand if we are freeing a 4k cunk then we just go to order 0 and enqueue it to   that end and update hte total value


buddy system means

let say we want to allocate 128k, but there no free chunks in order 5, so go next order and see tha we have free chunk here, but as we know every chunk in order 6 has size of 256 kb, we divide it into 2, send 128k to the rquester and we have 128k page now, we just endqueue to that previous order taht is 5 and update its total

when the requester frees the 128k that he initally got, the allocator will know that the other half is also in order 5, so it take dequeue both 128kb from order 5 and enqueue it back to order 6

this metthod of knowing the previous 128 kb chunk is called buddy blockk

time complexity is log n


Page Alllocator APIs

kernel provides a set of APIs to allocate and dellocate ram using page allocator

eg: `unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order);`

they all take two parameter, gfp bitmask and order in the bin list (the amout of memory to allocate in 2power order page frames)


GFP flags

there two flags that we need to care about, that describies how we want to allocate memory, that is it possible to sleep or wait during the allocation or should it happen attomicall

as we know that we can sleep within interrup context, butt we can sleep in process context,

this bit mask values tell the allocator which option to use, that way we could confirm that we wont sleep during the

GFP_KERNEL

GFP_ATOMIC

the rule the thumb is, if in process context and it is safe to sleep, use GFP_KERNEL flag, if it is unsafe to sleep, typically when in any type of atomic or interrupt context, you must use the GFP_ATOMIC flag

we can use `__GFP_ZERO` to make it allocate memory with zeros

Freeing page

we can dellocate a allocated page using common APIs like `void __free_pages(struct page *page, unsigned int order)` 

here we pass a page struct (not the address of start of page frame)

`free_pages` is just an wraper around `__free_page` , it is always advised to use the wrapper function instead of the acutal fucntion, as the wrapped might do some extra steps to makke sure the underlyinr call is done correctly

all functions with `__function_name` bypasses validity checks in favor of speed

when we are allocating and deallocating stuff, we face the common issues like
- memory leakage
- overflows/underfllows during read/write
- double free, free same location twice
- use-after-free, using a location that is already deallocated
- deferencing pointers that are already deallocated

dont manipulate the original pointer, as you need it to free it lated, double check the pointer are allocated properly before passing to other apis

always free things in the reverse order from which they were allocated

```
 show_phy_pages(): start kaddr ffff9d72c0000000, len 20480, contiguity_check is on
[127372.934169] -pg#-  -------va-------     --------pa--------   --PFN--
[127372.934169] 00000  0xffff9d72c0000000   0x0000000000000000   0
[127372.934171] 00001  0xffff9d72c0001000   0x0000000000001000   1
[127372.934172] 00002  0xffff9d72c0002000   0x0000000000002000   2
[127372.934173] 00003  0xffff9d72c0003000   0x0000000000003000   3
[127372.934174] 00004  0xffff9d72c0004000   0x0000000000004000   4

```

print showing the offset diff betwen va and pa

to check if the allocate memory is physical contginour memory, we coudl check the

[127372.934198] -pg#-  -------va-------     --------pa--------   --PFN--
[127372.934199] 00000  0xffff9d72d0948000   0x0000000010948000   67912
[127372.934200] 00001  0xffff9d72d0949000   0x0000000010949000   67913
[127372.934201] 00002  0xffff9d72d094a000   0x000000001094a000   67914
[127372.934202] 00003  0xffff9d72d094b000   0x000000001094b000   67915
[127372.934203] 00004  0xffff9d72d094c000   0x000000001094c000   67916
[127372.934204] 00005  0xffff9d72d094d000   0x000000001094d000   67917
[127372.934204] 00006  0xffff9d72d094e000   0x000000001094e000   67918
[127372.934205] 00007  0xffff9d72d094f000   0x000000001094f000   67919


PFN physical frame number