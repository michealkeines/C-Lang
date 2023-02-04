
commit infor format

```
majorsubsytem/minorsubsystem: comment

eg:

usbip/usbip_host: cleanup do_rebind() return path 
```

commit log should rpovide enough infor about the change 

author infor

.gitconfig file


![[Pasted image 20230126032359.png]]

sigining the commit

https://www.kernel.org/doc/html/latest/process/submitting-patches.html#sign-your-work-the-developer-s-certificate-of-origin


in email subjet we have to added `[PATCH]`

if we need comments then added `[PATCH RFC]`

if we are sending the updated version of previeus review `[PATCH v2]`


![[Pasted image 20230126033114.png]]


![[Pasted image 20230204111628.png]]

always run checkpatch 

```bash
git diff > temp; scripts/checkpatch.pl temp;
```


finally

```
git commit <filenames>
git format-patch -1 <commit ID>
```