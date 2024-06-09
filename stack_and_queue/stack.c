#include "stack.h"
#include <stdlib.h>
#include <string.h>



a_stack* stack_create(size_t size, data_type type)
{
    a_stack *s = (a_stack*) malloc(sizeof(a_stack));
    if(s == NULL){
        fprintf(stderr, "Could not allocate memory");
        exit(EXIT_FAILURE);
    }
    s->tos          = EMPTY_TOS;
    s->max_size     = size;
    s->stack_type   = type;
    
    if(type == INT_TYPE)
        s->element = (int*) malloc(sizeof(int) * size); 
    
    else if(type == STR_TYPE)
        s->element = (char*) malloc(sizeof(char*) * size);
    
    if(s->element == NULL){
        printf("Cannot allocate memroy\n");
        exit(EXIT_FAILURE);
    }
    return s;
}
void stack_dest(a_stack *S)
{
    free(S->element);
    free(S);
}
char* cpystr(char* src, char* dest)
{
    while(*dest){
        *src++ = *dest++;
    }
    *src ='\0';
    return src;
}
void push(void *elem, a_stack *stack)
{ 
    if(is_full(stack)){
        printf("Stack is full\n");
        exit(EXIT_FAILURE);
    }
    if(stack->stack_type == INT_TYPE){
        int a = *(int*) elem;
        ((int*)stack->element)[++stack->tos] = a; 
    }
    else if(stack->stack_type == STR_TYPE){
        size_t  len = strlen((char*)elem);
        char* str = (char*)stack->element; 
        size_t count = (++stack->tos * len);  
        str = cpystr(str++,(char*)elem);     
    }

}

void pop(a_stack *stack)
{
   if(is_empty(stack)){
        printf("Error: empty stack\n");
        exit(EXIT_FAILURE); 
    }
    --stack->tos; 
}

void* peek(a_stack *stack){
    if(is_empty(stack)){
        printf("Error: empty stack\n");
        exit(EXIT_FAILURE); 
    }
    return &stack->element[stack->tos--];
}
void make_null(a_stack *s)
{
    s->tos = EMPTY_TOS;
}

int is_full(a_stack *s)
{
    return s->tos == (int)(s->max_size + 1); 
}

int is_empty(a_stack *s)
{
    return s->tos == EMPTY_TOS;
}

void print_stack_int(a_stack *s)
{
    for(int i = 0; i <= s->tos ;++i){
        printf("Element[%d] = %d ",i,((int*)s->element)[i]);
    }
    printf("\n");
}
void print_stack_str(a_stack *s)
{
    char* tmp = s->element;
    for(int i = 0; i <= s->tos; ++i){
        printf("Element[%d] = %s ",i,tmp++);
    }
}


