CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb3 -o 


build: test.c binary_tree.c avl_tree.c
	$(CC) $(CFLAGS) test test.c binary_tree.c avl_tree.c 
run:
	./test
gdb:
	gdb ./test 
val:
	valgrind ./test
clean:
	rm -rf test
