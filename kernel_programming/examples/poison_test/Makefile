obj-m += poison-test.o
pwd := $(shell pwd)
cc := $(shell uname -r)

all:
	make -C /lib/modules/$(cc)/build M=$(pwd) modules
install:
	make -C /lib/modules/$(cc)/build M=$(pwd) modules_install
clean:
	make -C /lib/modules/$(cc)/build M=$(pwd) clean
