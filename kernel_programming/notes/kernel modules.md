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

obj-m = we want this object file to be separate from the actual kerel
obj-y = we want this object file to be included to the actual kernel code

make -C = this will change directory to the specfied location

M=PWD = after parsing the kernel Makefile, we are switching back to the original kernel module directory and the compiile it

if we have multiple source files

obj-m := fiinal.o
final-objs := file.o file2.0 file3.o

stacking kernel modules

write function in a code module and export those using EXPORT_SYMBOL

this way all other kernel module should be to call directly just by using extern

if we were to export it using EXPORT_SYMBOL_GPL, only other modules withj GPL lisence can use this 

during compilation, the dependencies c and object should also be present in the current working dirctory

if we want to removed stacked modules, we have to remove them top down

![[Pasted image 20230118112029.png]]

to pass argumemnt to the kernel module, we can set value during inseration

sudo insmod file.ko variable_name=value

to declare a variiable as something can pass, we use module_param macro

it takes there input,

module_param(
	variable_name,
	datatype,
	permission
)

```c
static int debug_mode;
module_param(
	debug_mode,
	int,
	0600
);
```

every module parameter will be mapped to file descriptor, that way, the users who have the permission can chagne the values during runtime or after instertion

located under `/sys/module/<module name>/parameters/`

```
// 4,2,1 => 7,

// w and r = 6 for current user and 0 for rest

// that how we got 600
```

if we have internal variable that we want to override, then we could use this marco to override the variable use a module paramter during insertion or dynamially using fd

```c
module_param_named(new_debug_mode, debug_mode, int, 0600);
```

to check the kernel logs, we can use dmesg command

to clear the kernel logs, `dmesg -C`


curent log level - all messages less than this will be printed to the console

default level for message that lack an explicit log level

the minimum allowed log level

the boot time default log level

![[Pasted image 20230116085028.png]]

we can jstu manipulate there values to chagne the log level

`echo "8 4 1 7" > printk`

every possible log will be passed to console

kernel logs buffer is /dev/kmsg


autoloading kernel moduels

- compile the kernel module
- using install copy the compiled module into /lib/modules
- create a config file under `/etc/modules-load.d/<module name>.conf`
- the config file content is just name of the kernel module withoout extension
- or we can oculd add the name of the module iinsdde module.conf file

after this if we restart the kernel, this module will be autolaoded

if we want to pass parameters to the autoloaded module,

we can use modprob

we have to create a config file with options that we want to set

`/etc/modprob.d/<module name>.conf`

```
option <module name> parameter=value
```

modules.order file is used by tthe kernel to load the modules in an order

modules.dep has the dependency information