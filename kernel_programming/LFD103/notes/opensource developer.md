
![[Pasted image 20230205072006.png]]

Many people ask me “how does one become a maintainer?” There are many paths to choose from. A few paths that lead you there:

    Write a new driver.
    Adopt an orphaned driver or a module (Hint: Check the MAINTAINERS file).
    Clean up a staging area driver to add it to the mainline.
    Work towards becoming an expert in an area of your interest by fixing bugs, doing reviews, and making contributions.
    Find a new feature or an enhancement to an existing feature that is important to the kernel and its ecosystem.
    Remember that new people bringing new and diverse ideas make the kernel better. We, as a community, welcome and embrace new ideas!



here are several ways to get started and contribute to the kernel. A few ideas:

    Subscribe to the Linux Kernel mailing list for the area of your interest.
    Follow the development activity reading the Linux Kernel Mailing List Archives.
    Join the #kernelnewbies IRC channel on the OFTC IRC network. Several of us developers hang out on that channel. This server is home to #mm, #linux-rt, and several other Linux channels.
    Join the #linux-kselftest, #linuxtv, #kernelci, or #v4l IRC channels on freenode.
    - This server recommends Nick registration. Server Name: irc.freenode.net/6667. You can register your Nick in the server tab with the command: identify /msg NickServ identify <password>
    - You can configure your chat client to auto-identify using the NickServ(/MSG NickServ+password) option - works on hexchat.
    Find spelling errors in kernel messages.
    Static code analysis error fixing: Static code analysis is the process of detecting errors and flaws in the source code. The Linux kernel Makefile can be invoked with options to enable to run the Sparse source code checker on all source files, or only on the re-compiled files. Compile the kernel with the source code checker enabled and find errors and fix as needed.
    Fix the Syzbot null pointer dereference and WARN bug reports which include the reproducer to analyze. Run the reproducer to see if you can reproduce the problem. Look ​​​​​​​at the crash report and walk through sources for a possible cause. You might be able to fix problems.
    Look for opportunities to add/update .gitignore files for tools and Kselftest. Build tools and Kselftest and run git status. If there are binaries, then it is time to add a new .gitignore file and/or an entry to an existing .gitignore file.
    Run mainline kernels built with the CONFIG_KASAN, Locking debug options mentioned earlier in the debugging section, and report problems if you see any. This gives you an opportunity to debug and fix problems. The community welcomes fixes and bug reports

