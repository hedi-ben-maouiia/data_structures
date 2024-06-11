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


TREE make_null(void);                       // Make TREE point to null
void tree_dest(TREE T);                     // Tree destructor 
TREE tree_insert(int key, TREE T);               // insert in normal tree randomly
TREE insert(int key, TREE root);        // insert in binary_search_tree
TREE search(int key, TREE T);               // Binary Search Tree
TREE find_min(TREE T);                      // Find minimum inside a binary_search_tree
TREE delete(int key, TREE T);               // Delete from binary_search_tree 
void in_order(TREE T);                      // print elements of tree inorder  
void pre_order(TREE T);                     // print elements tree pre_order 
void post_order(TREE T);                    // print elements tree post_order 
void recover_tree( TREE root);              // we have an wrong binary_search_tree with exactly two node swaped places and we send it to recover_tree to make it correct 





#endif // BINARY_TREE_H
