
use -l to link an library

if the lib name is libpthread, to link it use

gcc -o test test.c -l pthread, we can string the lib from that name

another example, if the lib name is librt, to link it,  use

gcc -o test test.c -l rt

![[Pasted image 20230107041616.png]]


just add -static to complie it statically

when linking statically, it take the libc.a and adds it iinto the binnary

to create a static lib, compile to the c file and use `ar` to combile them into a archive

`arm-cortex_a8-linux-gnueabi-gcc hello.c -ltest -o hello -L ./ -I ./`

-L is for custom lib directory
-I is for custom include headers directory

libtest should be in PWD

to make it shared

compile it with -shared

one of the requirement isthe the object files shoudl be position independt

they should have compiled with -fPic option

```
arm-cortex_a8-linux-gnueabi-gcc -fPIC -c test2.c
arm-cortex_a8-linux-gnueabi-gcc -fPIC -c test1.c
arm-cortex_a8-linux-gnueabi-gcc -shared -o libtest.so test1.o test2.o

arm-cortex_a8-linux-gnueabi-gcc hello.c -o hello -ltest -L ./ 
```

![[Pasted image 20230107045054.png]]


the linker will look for tis in defuatl location, we can add custom dirctories by adding this

export LD_LIBRARY_PATH=/opt/lib:/opt/usr/lib


![[Pasted image 20230107045335.png]]

/lib/ld-linux.so.3 is the linker for this file



we should also consider the version of the libs

 `It is formatted as <library name>.so.<interface number>`

eg: `libjpeg.so.8 which is symbolic llink to libjpeg.so.8.2.2`


her the lib name is jpeg, interface is 8.2.2

![[Pasted image 20230107045920.png]]

