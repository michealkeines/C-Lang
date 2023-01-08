make is the best tool in this space

autotools create a makefile automatically based on your env

so normal flow is 

```
./configure
make
sudo make install
```

common flags

```
CC = c compiler command
CFLAGS = addition c compiler flags
LDFLAGS = addition linker flags, custom dir for libs eg: -L /tmp
LIBS = flags for additoins libs eg: -lrt -lpthread
CPPFLAGS = preprocessor flags eg: -I custom include header dir
CPP = the c preprocessor to use
```

some time the configure might try to run some non-native code to find its capabilites,  to avaoid this, we could pass --host

![[Pasted image 20230107051803.png]]

```
CC=arm-cortex_a8-linux-gnueabihf-gcc \
./configure --host=arm-cortex_a8-linux-gnueabihf
```

the default installtion dir is `<sysroot>/usr/local/` we can change that using --prefix

```
CC=arm-cortex_a8-linux-gnueabihf-gcc \
./configure --host=arm-cortex_a8-linux-gnueabihf --prefix=/usr
```


custome isntal location

```
make DESTDIR=/tmp/usr/local install
```


manual

![[Pasted image 20230107112806.png]]

