cmd_/home/micheal/C-Lang/kernel_programming/examples/module_stacking/stacked.ko := ld -r -m elf_x86_64 -z noexecstack --no-warn-rwx-segments --build-id=sha1  -T arch/x86/module.lds -o /home/micheal/C-Lang/kernel_programming/examples/module_stacking/stacked.ko /home/micheal/C-Lang/kernel_programming/examples/module_stacking/stacked.o /home/micheal/C-Lang/kernel_programming/examples/module_stacking/stacked.mod.o;  true