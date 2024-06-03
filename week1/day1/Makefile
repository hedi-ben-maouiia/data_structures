CC=gcc 
CFLAGS=-Wall -Wextra -ggdb3 -pedantic -o 

build:
	$(CC) $(CFLAGS) basics basics.c 
val:
	valgrind ./basics 
gdb:
	gdb ./basics
run:
	./basics
clean:
	rm -rf basics
