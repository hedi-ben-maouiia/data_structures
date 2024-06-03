#include<stdio.h>


/* Okay let's start with pointers:
 *  - pointer is block of memory usueally 8 byte length in 64-bit machine.
 *  - you can check it by sizeof(*ptr)
 *  - When we declare a pointer we need to specify what type do we need our pointer to point to ?     
*/


typedef struct {
    char*  model;
    char*  brand;
    size_t speed;
} car;

int some_func(int y, int x)
{
    // do something here;
    return y + x; 
}

int main(void)
{
    /*here is an example to check the size of the pointer*/ 
    char* ptr;
    printf("Pointer size = %zu\n",sizeof(ptr));
    /*____________________________________________________*/
    /* Some example how we can declare a pointer */
    char* cptr;
    int*  iptr;
    size_t* ulptr;
    car* carptr;
    void* vptr;
    // This is a function pointer which a normale pointer but it point to an address of function  
    int (*func_ptr)(int,int); 
    func_ptr = &some_func;
    printf("Function pointer res = %d\n",func_ptr(2,2));
    // And there is some special relation between array and ptr 
    // for ex : 
    int arr[] = {2,3,45};
    
    // The arr = ptr to the first element of the array  arr = &arr[0] 
    // We can simply print the first element with derifrence the arr like this  
    
    printf("*arr = %d\n",*arr);

    // We cannot use arithmetic on array we just can reach it in O(1) by arr[i]
    // But in the other hand the pointer it can do arithmetic for theme
    /* 
     *  Each one of them is called a pointer but each one of them point to different data type
     *  And we use void* when we don't sure what data we gonna point to but it need to be cast in run time .
    */
    
    return 0;
}
