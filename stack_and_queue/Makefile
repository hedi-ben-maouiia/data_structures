CC=gcc 
CFLAGS=-Wall -Wextra -ggdb3 -pedantic -o 

test:	
	$(CC) $(CFLAGS) test test.c stack.c queue.c 
val:
	valgrind ./test 

gdb:
	gdb ./test
run:
	./test
clean:
	rm -rf test
