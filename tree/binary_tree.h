#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct tree_node *TREE; 
typedef struct tree_node {
    int     key;
    TREE    left;
    TREE    right;
} tree_node;


TREE make_null(void);
TREE insert(int key, TREE T);
TREE search(int key, TREE T);
TREE delette(int key, TREE T);
void in_order(TREE T);
void pre_order(TREE T);
void post_order(TREE T);

#endif // BINARY_TREE_H
