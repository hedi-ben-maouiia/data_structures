CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb3 -o 


build:
	$(CC) $(CFLAGS) test test.c binary_tree.c
run:
	./test
gdb:
	gdb ./test 
val:
	valgrind ./test
clean:
	rm -rf test
