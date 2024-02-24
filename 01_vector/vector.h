#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>

class Vector{
private:

    int* arr; 
    int size;
    // For the capacity trick
    int capacity;
    
        void expand_capacity();
public:
    Vector(int size);
    ~Vector();

    int get(int idx);
    void set(int idx, int val); 
    void print();
    int find(int val);
    int get_front();
    int get_back();
    void push_back(int val);
    void insertion(int idx, int val);
    // Homeworks functions 
    void right_rotate();
    void left_rotate();
    void right_rotate(int times);
    int pop(int idx);
    int find_transposition(int value);
};

#endif // !VECTOR_H
#define macro
