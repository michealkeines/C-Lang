

/etc/default/grub

GRUB_TIMEOUT=10
GRUB_TIMEOUT_STYLE=hidden

this allows us to get early printk in the screen

GRUB_CMDLINE_LINUX="earlyprintk=vga"


![[Pasted image 20230201121207.png]]

![[Pasted image 20230201121214.png]]

![[Pasted image 20230201121515.png]]

