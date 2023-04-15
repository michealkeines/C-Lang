
macros only replace the code with action code and replacing the parameters if any, i wont execute anything

if we add macro funtion, the comiler will have no idea of it ,as it will be replace with actual code

clang -E file.c or gcc -E file.c 

to get the expanded version of macros

#define can be left without any value

```
#define value

#ifdef value
	do somthing
```

we can also pass value for the value from command line using -D

gcc -Dvalue=12

`gcc -DINPUT="\"12\"" test1.c -o test1  passing string

`\` new lines mentioned by using backslash

Header guard using #ifndef

`#pragma once` this can use as an alternative for header guard, it is upported by most compilers

`#` ash is used to make the value inside double quotations

`##` double ash is used to concat two parameters, as in string

```c

#define command(name) \

char name ## _cmd[256] = ""; \

strcpy(name ## _cmd, #name);


command(copy)
command(paste)

output

char copy_cmd[256] = ""; strcpy(copy_cmd, "copy");
char paste_cmd[256] = ""; strcpy(paste_cmd, "paste");

```

variadic macros are useds to get variable numbesr so input arguments

