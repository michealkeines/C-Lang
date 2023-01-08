

to switch between tool chains

```bash
bin/ct-ng distclean
bin/ct-ng arm-unknown-linux-gnueabi
```

get default compiler options

```
arm-cortex_a8-linux-gnueabi-gcc -v

arm-cortex_a8-linux-gnueabihf-gcc --target-help
```

to override them just add those to the normal paramteters

```
arm-cortex_a8-linux-gnueabihf-gcc -mcpu=cortex-a5 \ helloworld.c \
-o helloworld 
```

print sysrooot

```
arm-cortex_a8-linux-gnueabihf-gcc -print-sysroot
```

![[Pasted image 20230107040800.png]]

