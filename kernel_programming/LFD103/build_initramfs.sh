# create a folder initramfs
mkdir initramfs

# create the needed root dirs

mkdir bin # /bin
mkdir sbin # /sbin
mkdir etc # /etc
mkdir proc # /proc
mkdir sys # /sys
mkdir newroot # /newroot, only needed if we are also mounting a file system

# this file is needed for older busy box setups, empty file
touch /etc/mdev.conf

# download busybox static binary

wget https://busybox.net/downloads/binaries/1.31.0-defconfig-multiarch-musl/busybox-x86_64 -O /bin/busybox

# give executable permissions

chmod +x /bin/busybox

# create a soft link to busybox as sh
ln -s /bin/busybox /bin/sh

# copy the standart init file

cp init_template /init

# give executable permissions

chmod +x /init

# within the initramfs dir, pack and gzip it

find . | cpio -H newc -o ../initramfs.cpio

cat ../initramfs.cpio | gzip > ../initramfs.igz

# run using qemu

qemu-system-x86_64 -smp 4 -m 4G \
    -kernel arch/x86/boot/bzImage \
    -initrd initramfs.igz \
    -append 'console=ttyS0 root=/dev/sda' \
    -netdev user,id=n1 \
    -device e1000,netdev=n1 \
    -nographic
