
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

to find how to send a kernel patch

we can use

```bash
scripts/get_maintainer.pl drivers/media/usb/uvc/uvc_driver.c
```

this is igve the email address we have attach all email and cc the open emails

```bash
scripts/get_maintainer.pl drivers/media/usb/uvc/uvc_driver.c
Laurent Pinchart <laurent.pinchart@ideasonboard.com> (maintainer:USB VIDEO CLASS)
Mauro Carvalho Chehab <mchehab@kernel.org> (maintainer:MEDIA INPUT INFRASTRUCTURE (V4L/DVB))
linux-media@vger.kernel.org (open list:USB VIDEO CLASS)
linux-kernel@vger.kernel.org (open list)


git format-patch -1 <commit ID> --to=laurent.pinchart@ideasonboard.com --to=mchehab@kernel.org --cc=linux-media@vger.kernel.org --cc=linux-kernel@vger.kernel.org

git send-email <patch_file>
```

https://www.kernel.org/doc/html/latest/process/submitting-patches.html#select-the-recipients-for-your-patch

https://www.kernel.org/doc/html/latest/process/submitting-patches.html#submitting-patches-the-essential-guide-to-getting-your-code-into-the-kernel


setup a post commit hook that will run checkpatch.pl 

.git/hooks/post-commit

```
#!bash
#!/bin/sh
exec git show --format=email HEAD | ./scripts/checkpatch.pl --strict --codespell
```

chmod +x .git/hooks/post-commit

if find warning, update and amend the commit

