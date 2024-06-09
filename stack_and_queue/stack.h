#ifndef STACK_H_
#define STACK_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define EMPTY_TOS (-1)


typedef enum data_type {
    INT_TYPE,
    STR_TYPE,
} data_type;


// stack using array 
typedef struct a_stack {
    size_t    max_size;
    data_type stack_type;
    int       tos;
    void*     element;
     
} a_stack;


a_stack *stack_create(size_t size,data_type type);
void    stack_dest(a_stack *stack);
void    push(void* elem, a_stack* stack);
void    pop(a_stack* stack);
void*   peek(a_stack*);
int     is_empty(a_stack* stack);
int     is_full(a_stack* stack);
void    print_stack_int(a_stack *stack);
void    print_stack_str(a_stack *stack);

// stack using linked list 
typedef struct l_stack {

} l_stack;



// TODO : 


#endif // STACK_H_
