
```
gcc -E file.c # expland all macros to get full code

gcc -S file.c # get assemply code for the c code, out: file.s

as file.s -o file.o # get object file from assembly code using assumbler

gcc -c file.c # get file.o directly

nm file.o # list the method in the object file, 

```

![[Pasted image 20230423084920.png]]

![[Pasted image 20230423085608.png]]


