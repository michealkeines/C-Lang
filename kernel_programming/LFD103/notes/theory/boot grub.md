

/etc/default/grub


There are a couple more important steps to take before trying out the newly installed kernel. There is no guarantee that the new kernel will boot. As a safeguard, please ensure that there is at least one good kernel installed. Change the default grub configuration file /etc/default/grub to:

    Enable printing early boot messages to vga using the earlyprink=vga kernel boot option
    Increase the GRUB_TIMEOUT value to 30 seconds, so grub pauses in menu allowing time to choose the kernel to boot from the grub menu, and comment out GRUB_TIMEOUT_STYLE=hidden

GRUB_CMDLINE_LINUX="earlyprink=vga"
#GRUB_TIMEOUT_STYLE=hidden
GRUB_TIMEOUT=30

Run update-grub to update the grub configuration in /boot:

sudo update-grub












