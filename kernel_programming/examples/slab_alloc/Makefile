obj-m += slab_alloc.o
pwd := $(shell pwd)
cc := $(shell uname -r)

all:
	make -C /lib/modules/$(cc)/build M=$(PWD) modules
install:
	make -C /lib/modules/$(cc)/build M=$(PWD) modules_install
clean:
	make -C /lib/modules/$(cc)/build M=$(PWD) clean


