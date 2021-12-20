Early Computers:

In 1933 Babbage started work on his Analytical Engine, a mechanical computer with all of the elements of a modern computer, including control, arithmetic, and memory, but the technology of the day couldn’t produce gears with enough precision or reliability to make his computer possible.

George Boole introduced what is now called Boolean algebra in 1854. This branch of mathematics was essential for creating the complex circuits in modern electronic digital computers.

In the 1900s, researchers started experimenting with both analog and digital computers using vacuum tubes. Some of the most successful early computers were analog computers, capable of performing advanced calculus problems rather quickly. 

The first modern computer was the German Zuse computer (Z3) in 1941. In 1944 Howard Aiken of Harvard University created the Harvard Mark I and Mark II.

The first modern electronic computer was the ENIAC in 1946, using 18,000 vacuum tubes.

The first solid-state (or transistor) computer was the TRADIC, built at Bell Laboratories in 1954. The transistor had previously been invented at Bell Labs in 1948.

input output control systems

The first programs directly controlled all of the computer’s resources, including input and output devices. Each individual program had to include code to control and operate each and every input and/or output device used.

 One of the first consolidations was placing common input/output (I/O) routines into a common library that could be shared by all programmers. I/O was separated from processing.

These first rudimentary operating systems were called an Input Output Control System or IOCS.

batch systems

Batch systems automated the early approach of having human operators load one program at a time. Instead of having a human operator load each program, software handled the scheduling of jobs. In addition to programmers submitting their jobs, end users could submit requests to run specific programs with specific data sets (usually stored in files or on cards). The operating system would schedule “batches” of related jobs. Output (punched cards, magnetic tapes, printed material, etc.) would be returned to each user.

Batch operating systems used a Job Control Language (JCL) to give the operating system instructions. These instructions included designation of which punched cards were data and which were programs, indications of which compiler to use, which centralized utilities were to be run, which I/O devices might be used, estimates of expected run time, and other details.

This type of batch operating system was known as a single stream batch processing system.

Eg: BKY, BOS/360, BPS/360, CAL, and Chios.

Multi-Programming:

  The early 1960s saw the introduction of time sharing and multi-processing.
  
  There is a huge difference in speed between I/O and running programs. In a single stream system, the processor remains idle for much of the time as it waits for the I/O device to be ready to send or receive the next piece of data.

The obvious solution was to load up multiple programs and their data and switch back and forth between programs or jobs.

When one job idled to wait for input or output, the operating system could automatically switch to another job that was ready.

 Timesharing is a more advanced version of multiprogramming that gives many users the illusion that they each have complete control of the computer to themselves. The scheduler stops running programs based on a slice of time, moves on to the next program, and eventually returns back to the beginning of the list of programs. In little increments, each program gets their work done in a manner that appears to be simultaneous to the end users.
 
 Eg: The Atlas I Supervisor introduced spooling, interrupts, and virtual memory paging (16 pages) in 1962. Segmentation was introduced on the Burroughs B5000. MIT’s Multics combined paging and segmentation.
 
 UNIX takes over mainframes
 
 In 1970 Ken Thompson of AT&T Bell Labs suggested the name “Unix” for the operating system that had been under development since 1969. The name was an intentional pun on AT&T’s earlier Multics project (uni- means “one”, multi- means “many”).
 
 UNIX quickly spread throughout the academic world, as it solved the problem of keeping track of many (sometimes dozens) of proprietary operating systems on university computers. With UNIX all of the computers from many different manufacturers could run the same operating system and share the same programs (recompiled on each processor).
 
 In 1973 the kernel of Unix was rewritten in the C programming language. This made Unix the world’s first portable operating system, capable of being easily ported (moved) to any hardware. This was a major advantage for Unix and led to its widespread use in the multi-platform environments of colleges and universities.
 
  The 1980s saw the commercial release of the graphic user interface, most famously the Apple Macintosh, Commodore Amiga, and Atari ST, followed by Microsoft’s Windows.
  
  
 