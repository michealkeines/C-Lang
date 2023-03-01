
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

