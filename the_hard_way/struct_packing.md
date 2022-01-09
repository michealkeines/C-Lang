# Structure Packing in C

By default structes are padded in c, to avoid this behaviour, you have to explicitly request it.

Consider this structrue 

struct foo {
	char * p;  // 8 bytes
	char c;    // 1 byte
	long x;    // 8 bytes
}

because char c is just one byte, it will be automatically padded

struct foo {
	char * p;     // 8 bytes
	char c;	      // 1 byte
	char pad[7];  // 7 bytes padding added by the compiler
	long x;       // 8 bytes
}

So sizeof(struct foo) will give us 24 instead of 17.

this happened because of a 64-bit compiler r/w from/to memory in 8 bytes of word in each step and obvious,

when we try to write char c; a one byte in memory a complete 8 bytes fetched and consumes only first byte of it and its seven succesive bytes remains empty and not accessible for any read and write operation.

We can add the attribute packed, to make the compiler not add any packing

struct __attribute__((__packed__)) foo {
	char * p;  // 8 bytes
	char c;    // 1 byte
	long x;    // 8 bytes
}

now, the sizeof(struct foo) will return 17.


Generally packed structures are used to

save space,
to formatt data structure to transmit over network


