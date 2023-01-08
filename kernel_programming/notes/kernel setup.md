
kernel version

`major#.minor#[.patchlevel][-EXTRAVERSION]`

eg: `5.0.0-36-generic`

![[Pasted image 20230108011624.png]]

make file will look for default configuration in .config file in root folder, if it not there, it will fall back to default config

we can go to `/arch/<type>/configs` to get defautl configs for many archs, and copy that into .config in root

eg: `cp arch/x86/configs/x86_64_defconfig .config`

configuring kernal 

![[Pasted image 20230108020409.png]]


vmlinux - uncompress kernnel image

baimage - is the compressed kernel image that will be uncompress in memory and boot iinto

make menuconfig

make all

make modules_install ot isntall modules under /lib/modules

make INSTALL_MOD_PATH=${STG_MYKMODS} modules_install

to install to different location

/lib/modules - will have kerneral version specific modules

