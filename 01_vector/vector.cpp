#include<iostream>
#include<assert.h>
#include <type_traits>
#include"vector.h"

int* arr = nullptr;
int size {0};
int capacity { };

Vector::Vector(int size) : size(size) {
    if(size < 0)
        size = 1;
    capacity = size + 10;  
    arr = new int[capacity] { };
}

Vector::~Vector(){
    delete[] arr;
    arr = nullptr;
}

int Vector::get(int idx){
    assert(0 <= idx && idx < size);
    return arr[idx];
}

void Vector::set(int idx, int val){
    assert(0 <= idx && idx < size);
    arr[idx] = val;
}
    
void Vector::print(){
    for(int i{0}; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int Vector::find(int val){
    for(int i{0}; i < size; ++i)
        if(arr[i] == val)
            return i;
    return -1;
}
    
int Vector::get_front() {
    return arr[0];
}

int Vector::get_back() {
    return arr[size-1];
}

void Vector::expand_capacity(){
    capacity *= 2;
    int* arr2 = new int[capacity] { };
    
    for(int i{0};i<size;++i)
        arr2[i] = arr[i];  
    
    std::swap(arr, arr2); 

    delete[] arr2;
}

void Vector::push_back(int val){
    // first check if the size grow to the capacity or not yes !
    if(size == capacity)
        expand_capacity(); // we make the capacity double
    
    arr[size++] = val; // then we add the previous size and we incremented 
}

void Vector::insertion(int idx, int val){
    assert( 0 <= idx  && idx <= size);
    
    // we cannot add anymore 
    if(size == capacity) 
        expand_capacity();

    //Shift all teh data to right first
    for(int i=size-1; i >= idx;--i)
        arr[i+1] = arr[i];

    arr[idx] = val;
    ++size;

}
