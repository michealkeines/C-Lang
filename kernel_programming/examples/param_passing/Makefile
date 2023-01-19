PWD := $(shell pwd)
obj-m += param_pass.o

uu := $(shell uname -r)

all:
	make -C /lib/modules/$(uu)/build M=$(PWD) modules
install:
	make -C /lib/modules/$(uu)/build M=$(PWD) modules_install
clean:
	make -C /lib/modules/$(uu)/build M=$(PWD) clean
