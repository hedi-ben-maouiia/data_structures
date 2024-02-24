/*
    *
    *
    *   Vector Homeworks - 5 Medium Challanges
    *
    *
*/ 

#include"vector.h"

// Problem #1 : right rotation 
void Vector::right_rotate(){
    int temp = arr[size-1];
    for(int i{size-1};i >= 0;--i)
        arr[i+1] = arr[i];

    arr[0] = temp;
}
 

// Problem #2 : left rotation 
void Vector::left_rotate(){
    int tmp = arr[0];
    for(int i{1}; i < size; ++i)
        arr[i-1] = arr[i];
    arr[size-1] = tmp;
}

// Problem #3 : Right rotation with steps 
void  Vector::right_rotate(int times){
    times %= size;
    while(times--)
        right_rotate();
}

// Problem #4 : Delete a position 
int Vector::pop(int idx){
    int tmp = arr[idx]; 
    for(int i{idx}; i < size;++i)
        arr[i] = arr[i+1];
    size--;
    return tmp; 
}

// Probblem #5 : Improved search 
int Vector::find_transposition(int value){
    // first we check if the value already in the head of the array or not  
    if(!find(value))
        return 0;
    int idx_val = find(value);
    // then we swap between the value and his left nighbored 
    std::swap(arr[idx_val], arr[idx_val - 1]);
    // we return the value that we found in the
    return idx_val - 1 ;
}


