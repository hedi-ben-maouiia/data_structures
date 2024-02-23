#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>

class Vector{
private:

    int* arr; 
    int size;
    // For the capacity trick
    int capacity;
public:

    Vector(int size);
    ~Vector();

    int get(int idx);
    void set(int idx, int val); 
    void print();
    int find(int val);
    int get_front();
    int get_back();
    void expand_capacity();
    void push_back(int val);
};

#endif // !VECTOR_H
#define macro
