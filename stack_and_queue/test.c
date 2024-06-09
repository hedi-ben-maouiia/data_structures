#include "stack.h"


int main(void)
{
    int x = 234;
    int y = 559;
    int z = 40;
    a_stack *arr_stack = stack_create(10,INT_TYPE);
    
    push(&x,arr_stack);   
    push(&y,arr_stack); 
    push(&z,arr_stack); 
    a_stack *s = stack_create(100,STR_TYPE);
    push("hello",s);
    push("World",s);
    pop(arr_stack);
    print_stack_int(arr_stack);   
    print_stack_str(s);
    stack_dest(s);
    stack_dest(arr_stack);
    return 0;
}
