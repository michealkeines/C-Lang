obj-m += iterating_threads.o 
pwd := $(shell pwd)
uu := $(shell uname -r)

all:
	make -C /lib/modules/$(uu)/build M=$(pwd) modules
install:
	make -C /lib/modules/$(uu)/build M=$(pwd) modules_install
clean:
	make -C /lib/modules/$(uu)/build M=$(pwd) clean

