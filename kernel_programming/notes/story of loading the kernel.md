
the root filesystem is on the disk and yet to be mounted, kernel image is in RAM 

in order for the kernel to mount the root filesystem, it requires the `reiserfs.ko` kernal module to be loaded into RAM, but that file itself is embedded inside rote filesystem `/lib/moduels/<kernel version>/kernel/fs/reiserfs`

initramfs framework is to solve this problem

it contains a minimal root filesystem containing kernel modules as well as supporting infrastruccture such as /etc /lib dirs