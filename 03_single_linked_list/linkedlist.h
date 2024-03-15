#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<iostream>
using namespace std;
struct NODE {
    int  data;
    NODE* next;
    // Pointer to SAME type 
    NODE(int data) : data(data) {}
};

class linked_list {
private:
    NODE* head { };
    NODE* tail { };
    int length {0}; 
public:
    void print();
    void insert_end(int value);
    int search(int value);
    int improved_search(int value);
};

#endif // !DEBUG
