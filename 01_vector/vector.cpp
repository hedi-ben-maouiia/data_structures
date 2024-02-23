#include<iostream>
#include<assert.h>
#include <type_traits>
#include"vector.h"

int* arr = nullptr;
int size = 0;
int capacity = 0;

Vector::Vector(int size) : size(size) {
    if(size < 0)
        size = 1;
    arr = new int[size] {};
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
void Vector::add_size(){
    int* arr2 = new int[size+10];
    for(int i{0};i<size;++i)
        arr2[i] = arr[i];
    std::swap(arr, arr2);
    delete[] arr2;
}

void Vector::push_back(int val){
    // We make a new arr with size+1 width;
    int* arr2 = new int[size+1]; // size + 1 steps

    // copy the old arr to the new one
    for(int i{0};i<size;++i)    // 3 size + 1 steps
        arr2[i] = arr[i];
   
    // add the new value to it's position  
    arr2[size++] = val;         // 2 stpes
    
    // now we swap the pointers 
    std::swap(arr,arr2);        // 3 steps 
    
    // Remove the temporary array that we don't need it anymore 
    delete[] arr2;              // size steps 

    // Total: 5size + 7
}
