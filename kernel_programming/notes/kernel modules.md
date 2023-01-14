Visualize a sceanrio where you hhave to add a support feature to the linux kernel or a new device driver in order to use a certian hardware peripheral chip.


if we were to add this directly to the kernel source, every change in the code that we write, no matter how minor, will require us to build the kernel image and then reboot the system in order to test it. 

the easier way is the LKM linux kernel modules

It is also referred to as out-of-tree code

kernel modules are merely a binary object file and not a binary executable.

after linux 2.4 the object file iis names with .ko extension before that it was just .o

A kernel module is only allowed to access a subset of full kernel APIs

to add this module into a live kernel, we use the insmod system call

![[Pasted image 20230111112328.png]]

kernel modulles live under /lib/modules/kernelversion/kernel

![[Pasted image 20230112081745.png]]

we can use lsmod to list modules

we can use modinfo to get infor about a modules


if it were between (-1 ot -4095), in that case IS_ERR() will consider it as error, if not ,we could just typecast it to void 

to insert the module into the kernel

`sudo insmod ./<name>.ko `

to delete the module form the kernel

`sudo rmmod <module_name>`


makefile

```bash
PWD   := $(shell pwd)
obj-m += hello_world.o

uu := $(shell uname -r)

all:
        make -C /lib/modules/$(uu)/build/ M=$(PWD) modules
install:
        make -C /lib/modules/$(uu)/build/ M=$(PWD) modules_install
clean:
        make -C /lib/modules/$(uu)/build/ M=$(PWD) clean
```


to check the kernel logs, we can use dmesg command

to clear the kernel logs, `dmesg -C`

