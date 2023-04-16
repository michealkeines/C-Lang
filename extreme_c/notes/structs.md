
memory aligment is important to think about, as it degrades performance, if not aligned properly

compiler does the padding make it alligned

the developer should make the design choice to make the struct memory aligned and be feteched in few cycles

we can also tell compiler not to pad the struct, that would make it a packed struct

step size of struct pointers is also size of the struct

