
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

![[Pasted image 20230228124025.png]]



if we allocote left 1 kb, we dequeue 1kb from 0th index, and when deallocation, we enqueue it back to that pointer

we can look at this list using /proc/buddyinfo

![[Pasted image 20230228125005.png]]

so in node 0 zone DMA32, in order 0 we have 3173 4kb free chunks
in node 0 zone DMA, in order 3 we have 37 32kb free chunks



![[Pasted image 20230228124922.png]]
every zone has its own order of free lists

