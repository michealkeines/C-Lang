cmd_/home/micheal/C-Lang/kernel_programming/examples/hello_world/hello_world.mod := printf '%s\n'   hello_world.o | awk '!x[$$0]++ { print("/home/micheal/C-Lang/kernel_programming/examples/hello_world/"$$0) }' > /home/micheal/C-Lang/kernel_programming/examples/hello_world/hello_world.mod
