
we always have visualize the address space in terms of pages

![[Pasted image 20230209112337.png]]

everry virtual address is divided into parts representing the page index and the actual offet in the physical page

in the page tage, every virual page is mapped to physical page and we only get he top address the page

![[Pasted image 20230209112314.png]]

once we get hte top address, we can adde the offset to it and get the acutal physical address

![[Pasted image 20230209112622.png]]


physical page base address + offset gives us the acutal address

![[Pasted image 20230209113022.png]]

the phycial framems may not be in sequential order, it can be mapped to whatever that was available at that point of excution

sharing memroy using same mapping to page

![[Pasted image 20230209113750.png]]

in this example all the three process has page 1 mapped to physical frame 3


multi level pagging

![[Pasted image 20230209114033.png]]

in this p1 will give page address withing p1v

p1v + p2 will give p2v

p2v + d offet will ve th physical address

