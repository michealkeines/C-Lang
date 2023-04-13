
Critical section

when a code is considered to be in a critical section, it has to either run exclusively or without interruptiion

atomic operations are indivisable eg: system call, dont really get scheduled off as they are atomic in nature

there are two things that are completely attomic

that is

-> single machine language instrucion

mov rbp, rsp

-> read/writes from memory using bus, that is typicllay as big as the arch bit, in 64 bit arch, reading a u64 vlaue willbe atomiic

![[Pasted image 20230413122249.png]]

rules


    (Always) Exclusively: Alone (serialized)
    (When in an atomic context) Atomically: Indivisibly, to completion, without interruption


