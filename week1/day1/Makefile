CC=gcc 
CFLAGS=-Wall -Wextra -ggdb3 -pedantic -o 

list:
	$(CC) $(CFLAGS) list  linked_list.c 	
dlist:
	$(CC) $(CFLAGS) dlist double_linked_list.c 	
val:
	valgrind ./dlist 
gdb:
	gdb ./dlist
run:
	./list
clean:
	rm -rf dlist
