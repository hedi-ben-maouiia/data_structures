#ifndef QUEUE_H_
#define QUEUE_H_

#include<stdio.h>

typedef int  elem_type;

// Queue using array 
typedef struct a_queue { 
    size_t     front;
    size_t     rear;
    size_t     q_size;
    size_t     max_size;
    elem_type  arr[];  
} a_queue;

typedef a_queue* QUEUE;

// Queue using linked list 
/*
typedef struct l_queue {

} l_queue;
*/


// TODO : 
void make_null(QUEUE aq);
void enqueue(QUEUE aq, elem_type elem);
void dequeue(QUEUE aq);
int  front(QUEUE aq);
int  is_empty(QUEUE aq);
void make_empty(QUEUE aq);

#endif // QUEUE_H_
