#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

TREE make_null(void)
{
    return NULL;
}
TREE create_node(int key)
{
    TREE T = (TREE) malloc(sizeof(tree_node));
        if(T == NULL)
            fprintf(stderr,"Cannot allocate memory\n");
        T->key = key;
        T->left = T->right = NULL;
        return T; 
}
TREE insert(int key, TREE T)
{
    if(T == NULL){
        T = create_node(key);        
    } 
    else if(T->left == NULL)
        T->left = insert(key, T->left);

    else if(T->right == NULL)
        T->right = insert(key, T->right);
    
    else if(T->right != NULL && T->left != NULL){
        T->left = insert(key,T->left);
    } 
    return T;  
}
void in_order(TREE T)
{
    if(T != NULL){
        in_order(T->left);
        printf("%d ", T->key);
        in_order(T->right);
    }
}
void post_order(TREE T)
{
    if(T != NULL){
        post_order(T->left);
        post_order(T->right);
        printf("%d ",T->key);  
    }
}
void pre_order(TREE T)
{
    if(T != NULL){
        printf("%d ", T->key);
        pre_order(T->left);
        pre_order(T->right);
    }
}
void tree_dest(TREE T)
{
    TREE tmp = T; 
    if(tmp == NULL)
        return;
    tree_dest(T->left);
    tree_dest(T->right); 
    free(tmp);
}

// Binary Search Tree 
TREE bst_inster(int key, TREE root)
{
    if(root == NULL){
        root = create_node(key); 
    }
    else if(key < root->key){
        root->left = bst_inster(key,root->left);
    }
    else if(key > root->key) {
        root->right = bst_inster(key, root->right);
    }
    return root;
}

TREE search(int key, TREE root)
{  
    if((root == NULL) || (root->key == key))
        return root;
    if(key < root->key)
        return ( search(key, root->left) );
    else 
        return ( search(key, root->right) ); 
}

int main(void)
{
    TREE bst = make_null();
    TREE T = make_null();
    for(int i = 1; i <= 10; ++i ){
        T= insert(i,T);
    }
    bst = bst_inster(50, bst);
    bst = bst_inster(40, bst);
    bst = bst_inster(60, bst);
    bst = bst_inster(70, bst);
    bst = bst_inster(10, bst);
    bst = bst_inster(20, bst);
    TREE tmp = search(60,bst); 
    printf(" we find %d in bst\n", tmp->key); 
    in_order(T);
    printf("\nBST={In order: "); 
    in_order(bst);
    printf(" Pre order: "); 
    pre_order(bst);
    printf("}\n"); 
    post_order(T); 
    printf("\n"); 
    pre_order(T); 
    tree_dest(T);
    tree_dest(bst);
}

