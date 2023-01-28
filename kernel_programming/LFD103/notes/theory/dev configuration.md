```
basics

sudo apt-get install build-essential vim git cscope libncurses-dev libssl-dev bison flex

sudo apt-get install git-email
```

check minimum requirements to compiel a kernel

```
https://www.kernel.org/doc/html/latest/process/changes.html
```


configuring git-email

```
.gitconfig

[user]
    name = Micheal Keines
    email = keinesmicheal@gmail.com
[sendemail]
    smtpServer = smtp.gmail.com
    smtpServerPort = 587
    smtpEncryption = tls
    smtpUser = keinesmicheal@gmail.com
    # (Optional: we'll leave this commented out and use a different way)
    # smtpPass = PASSWORD
[credential]
    helper = store


https://stackoverflow.com/questions/68238912/how-to-configure-and-use-git-send-email-to-work-with-gmail-to-email-patches-to

set up app password for the gmail account, that way you will get an unique pass that you can use for this 

credentials will be stored under .git-credentials
```


![[Pasted image 20230128025835.png]]

```

git format-patch -1 HEAD

git send-email --to=my_email@gmail.com patchname.patch
```


## Guidelines

Bottom Post: Add you resposne at the botton of the original text 

Inline Post: when responding to a patch, deleting or stripping parts of the message you are not replygin to is a good practice and makes it easier to follow responses in the thread

No HTML format: Patches sent using HTML format wlil be rejected by the deve mailing list automatically

No signatures: do not include private information in your sigunation. as you are going to be apostin to mailing lists

No attachements: Do not send patches as attachments, in General, avoid attachments. Some execeptions are kenel logs or configuration files when reporting bugs




