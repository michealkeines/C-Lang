
email: keinesmicheal@gmail.com

`Commit id - 0136d86b78522bbd5755f8194c97a987f0586ba5`

compiled the kali distro

## Steps

```bash

# copy old config
cp /boot/config-6.0.0-kali6-amd64 .config

# update the defaults for new config variables

make listnewconfig # paste the extra variabled insdie .config

make -j4 # compile

sudo make modules_install # install modules

sudo make install # copy the artifcats into /boot

sudo update-grub # update grub

```

![[Pasted image 20230204131801.png]]