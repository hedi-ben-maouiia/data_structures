#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef enum data_type {
    INT_SIZE,
    STR_SIZE,
} data_type ;

typedef struct node* node_ptr;
typedef struct node{
    void*        data;
    data_type    type;
    node_ptr     next;
} node;

typedef struct {
    node_ptr head;
    node_ptr tail;
} List;

#endif // LINKED_LIST_H
