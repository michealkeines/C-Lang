
Generators - we you create the program that will create vaild input for the appllication that youre fuzzing

Mutation - when you have one input, but you just mutate its properties, like a image iwth 50px and 100 px etc

![[Pasted image 20230212040931.png]]

![[Pasted image 20230212041158.png]]

![[Pasted image 20230212041258.png]]


Coverage guided fuzz

![[Pasted image 20230212042603.png]]

everrytime we hit a new line or code, we save that state and build on top of it


![[Pasted image 20230212042750.png]]


one-byte off issue 

![[Pasted image 20230212043036.png]]

as one-byte might not cause crash, this way even a single byte read could be foudn

 ![[Pasted image 20230212044051.png]]


Read after write RAW memory

if a memory allocated and read before being written once

