CC=gcc 
CFLAGS=-Wall -Wextra -ggdb3 -pedantic -o 


build:
	$(CC) $(CFLAGS) list linked_list.c 
val:
	valgrind ./list 
gdb:
	gdb ./list
run:
	./list
clean:
	rm -rf list
