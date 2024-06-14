#ifndef  AVL_TREE_H
#define  AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avl_node *AVL_TREE;
typedef struct avl_node {
    int         key;
    int         height;
    AVL_TREE    left;
    AVL_TREE    right;
} avl_node;

int get_height(AVL_TREE root);
AVL_TREE create_tree_node(int key);
AVL_TREE avl_insert(AVL_TREE root, int key);
void avl_pre_order(AVL_TREE root);
void avl_tree_dest(AVL_TREE T);



#endif // AVL_TREE_H
