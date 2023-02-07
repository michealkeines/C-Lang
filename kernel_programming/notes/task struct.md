
every thread has its own unique task_struct and kernel identifiies it using PID

but we want share PID with a parent, in that case its causing an issue


Thread Group ID, TGID,

if the process is single threade then TGID and PID will be the same,

if it is multiprocess, then TGID Of the main thread will equal to its PID and other thread threas will just hold same TGID butt their own unique PID

for ps -LA

PID - will tgid
LWP - will pid

cat /proc/tgid/task all dir under this are pids

