FLAGS=-Wall -g --std=c99
CC=Clang

FILE1=append_only
FILE2=atomic_append

all:
	$(CC) $(FLAGS) -o $(FILE1) $(FILE1).c

rm:
	rm $(FILE1)

atomic:
	$(CC) $(FALGS) -o $(FILE2) $(FILE2).c

atomic-rm:
	rm $(FILE2)

