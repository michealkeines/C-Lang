
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

