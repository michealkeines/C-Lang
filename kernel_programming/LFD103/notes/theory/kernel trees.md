
The kernel code is organized in several main and subsystem git repos called trees

### The MainLine kernel tree

This tree is maintained by Linus, this is where linux releases mainline kernels and RC releases

### The stable tree

This tree is maintained by Greg, This tree consists of stable release branches. stable releases are based on this tree

### The linux-next tree

This is the integration tree maintinaed by stephen. code from a large number of subsystem trees gets pulled into this tree periodically and then released for integration testing


each major subsystem has its own tree and maintainers



the flow is

my-patch tree (me) ----> sub-system tree (sub system maintainer) ----> linux-next tree (stephen) ----> mainline tree (Linux) ----> stable tree (Creg)



the developers send their patches to mainters specific to the subsystem, the mainters pull it into their sub system tree, then the send a pull request with enough patches and tested to linux-next tree

![[Pasted image 20230126022152.png]]







