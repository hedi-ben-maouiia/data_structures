#include "binary_tree.h"

TREE make_null(void)
{
    return NULL;
}

TREE create_node(int key, color rb)
{
    TREE T = (TREE) malloc(sizeof(tree_node));
        if(T == NULL)
            fprintf(stderr,"Cannot allocate memory\n");
        T->key = key;
        T->rb  = rb;
        T->left = T->right = NULL;
        return T; 
}

TREE tree_insert(int key, TREE T)
{
    if(T == NULL){
        T = create_node(key,RED);        
    } 
    else if(T->left == NULL)
        T->left = tree_insert(key,T->left);

    else if(T->right == NULL)
        T->right = tree_insert(key,T->right);
    
    else if(T->right != NULL && T->left != NULL){
        T->left = tree_insert(key,T->left);
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

// Binary Search Tree functions implementations
TREE insert(int key, color rb,TREE root)
{
    if(root == NULL){
        root = create_node(key,rb); 
    }
    else if(key < root->key){
        root->left = insert(key,BLACK,root->left);
    }
    else if(key > root->key) {
        root->right = insert(key,RED,root->right);
    }
    return root;
}
TREE first,prev,second; 

void inorder_traversal(TREE root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    if(prev != NULL && root->key < prev->key){
        if(first == NULL)
            first = prev;
        second = root;
    }
    prev = root;
    inorder_traversal(root->right);  
}

void recover_tree( TREE root) {
    if(root == NULL)
        return;
    first = NULL, second = NULL, prev = NULL;
    inorder_traversal(root);
    
    int tmp = first->key;
    first->key  = second->key;
    second->key = tmp; 
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

TREE find_min(TREE T)
{
    if(T == NULL )
        return NULL;
    if(T->left == NULL) 
        return T;     
return ( find_min(T->left) ) ;

}

TREE delete( int key, TREE T )
{
    TREE to_remove, child;
    if (T == NULL){
        fprintf(stderr,"ERROR: there is no such number %d to be delete \n",key);
        return NULL; 
    }
    else 
    if (key < T->key )
        T->left = delete(key,T->left);
    else 
    if (key > T->key)
        T->right = delete(key, T->right);
    else 
    if (T->left && T->right)
    {
        to_remove = find_min(T->right);
        T->key    = to_remove->key;
        T->right  = delete(T->key,T->right);
    }    
    else 
    {
        to_remove = T;
        if(T->left == NULL)
            child = T->right;
        if(T->right == NULL)
            child = T->left;
        free(to_remove);
        return child;
    } 
return T;
}



