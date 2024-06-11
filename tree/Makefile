CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb3 -o 


build:
	$(CC) $(CFLAGS) binary binary_tree.c
run:
	./binary
gdb:
	gdb ./binary 
val:
	valgrind ./binary 
clean:
	rm -rf binary 
