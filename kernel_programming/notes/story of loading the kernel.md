
the root filesystem is on the disk and yet to be mounted, kernel image is in RAM 

in order for the kernel to mount the root filesystem, it requires the `reiserfs.ko` kernal module to be loaded into RAM, but that file itself is embedded inside rote filesystem `/lib/moduels/<kernel version>/kernel/fs/reiserfs`

initramfs framework is to solve this problem

it contains a minimal root filesystem containing kernel modules as well as supporting infrastruccture such as /etc /lib dirs


steps:

BIOS loads up the first sector of the first bootable disk into RAM and jumps to its entry point, this is alse called as the stage one bootloader, its only job is to load stage two bootloader into memory and jump to it

stage two bootloader loads the GRUB bootloader into memory and jumps to its entry point

GRUB will be the thrid state bootloader

GRUB is passed with following arguments

`GRUB <kernel image> <initramfs>`

`GRUB /boot/vmlinz/kernal /boot/intird-img`

GRUB does the follwing


Perform low-level hardware initialization
Load these images into RAM, uncompress the kernel image to a certain point 
jump to kernel entry point

after a bit intialization, kernel mounts initramfs in ram, the startup scripts inside initramfs will load the needed modules to load the full root filesystem

now the kernel pivots from initrd filesystem to root filesystem

now the first usersapce process is started /sbin/init with pid 1



we can use

`lsinitramfs initrd.img-6.0.0-kali3-amd64`

to list the filesystem inside any initrd img


`/etc/default/grub` has the grub settings 

