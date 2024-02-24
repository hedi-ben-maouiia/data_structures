#include"vector.h"
#include<stdio.h>

int main(){
    Vector v(10);
 
    for(int i{0}; i < 10;++i)
        v.set(i, i); 

    v.print();

    int n; 
    scanf("%d", &n);
   
    v.right_rotate(n);
    
    v.print();
    
    v.left_rotate();

    v.right_rotate(); 
    v.print();
    
    v.insertion(2,939);
    v.push_back(7543);
    int a = v.pop(2);  

    printf("#########################\n");
    
    v.print();
    printf("the deleted number = %d\n", a);

    for(int i{0}; i<4;++i)
        printf("Position of 9 = %d\n", v.find_transposition(9)); 

    v.print();
}
