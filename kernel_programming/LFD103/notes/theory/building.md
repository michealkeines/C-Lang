
```
cp /boot/config-5.13.0-52-generic .config
make listnewconfig
```

copy the current kernel config
copy the listnewconfig value back into .config


CONFIG_DEBUG_INFO_BTF=n (success complitation, i set it to n)

remove pem files

building this atleast took 3-4 hrs

