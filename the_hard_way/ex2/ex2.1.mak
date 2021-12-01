CFLAGS=-Wall -g

all: ex2.c
		cc $(CFLAGS) -o ex2 ex2.c

clear:
	rm -f ex2
