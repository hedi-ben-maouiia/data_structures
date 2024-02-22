#include<iostream>
#include<assert.h>
#include"vector.h"


int* arr = nullptr;
int size = 0;


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

