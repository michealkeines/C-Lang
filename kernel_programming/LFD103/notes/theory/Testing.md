Testing is an integral and essential part of any software developmment cycle, open or closed, and the kernel is no exception to that.

Developer testing, integration testing, regressing and stress testing, security testing have different individual goal. however the end goal is the same. to ensure the software continues to work as it did before adding a new body ofcode and the new feature work as designed.


Automated bots are already pull all new rc branches and buildinng them on all different archs


to apply a patch

```
git apply --index file.patch
```


## Basic testing

Once the new kernel is up and running, check dmesg for any regressions. Run a few usage tests:

    Is networking (wifi or wired) functional?
    Does ssh work?
    Run rsync of a large file over ssh
    Run git clone and git pull
    Start a web browser
    Read email
    Download files: ftp, wget, etc.
    Play audio/video files
    Connect new USB devices - mouse, USB stick, etc.


check diff between preview dmesg out with current, see if there is no errors, warning etc

```
dmesg -t -l emerg
dmesg -t -l crit
dmesg -t -l alert
dmesg -t -l err
dmesg -t -l warn
dmesg -t -k
dmesg -t
```


## stess testing

run four kernel compiles in parallel and check the timing

## debugging locks, memory leaks

add the configs to get detailed warining 

```
CONFIG_KASAN
CONFIG_KMSAN
CONFIG_UBSAN
CONFIG_LOCKDEP
CONFIG_PROVE_LOCKING
CONFIG_LOCKUP_DETECTOR
```

Running Running git grep -r DEBUG | grep Kconfig can find all supported debug configuration options. can find all supported debug configuration options.

before and after installing a new kernel

```
dmesg -t > dmesg_current
dmesg -t -k > dmesg_kernel
dmesg -t -l emerg > dmesg_current_emerg
dmesg -t -l alert > dmesg_current_alert
dmesg -t -l crit > dmesg_current_crit
dmesg -t -l err > dmesg_current_err
dmesg -t -l warn > dmesg_current_warn
```