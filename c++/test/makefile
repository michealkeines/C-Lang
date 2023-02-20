CC=g++

final: file1.o file2.o
	$(CC) file1.o file2.o -o final
file1.o: file1.cpp
	$(CC) -c file1.cpp
file2.o: file2.cpp
	$(CC) -c file2.cpp
