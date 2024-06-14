#include "avl_tree.h"
#include <stdlib.h>


// Utilitie to get the height of the current tree;
int get_height(AVL_TREE root)
{
    if (root == NULL)
        return 0;
    else return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_balance_factor(AVL_TREE root)
{
    if(root == NULL)
        return 0;
    return get_height(root->left) - get_height(root->right); 
}

AVL_TREE create_tree_node(int key)
{
    AVL_TREE root = (AVL_TREE) malloc(sizeof(avl_node));
    if(root == NULL){
        fprintf(stderr,"ERROR: Cannot allocate memory\n");
        exit(EXIT_FAILURE); 
    }
    root->key      = key;
    root->height   = 1; 
    root->left     = NULL;
    root->right    = NULL;
    
    return root;
}
AVL_TREE right_rotate(AVL_TREE y)
{
    AVL_TREE x  = y->left;
    AVL_TREE t2 = x->right;
    
    x->right = y;
    y->left  = t2;

    y->height = max(get_height(y->left), get_height(y->right)) + 1; 
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
   

    return x;
}

AVL_TREE left_rotate( AVL_TREE y)
{
    AVL_TREE x  = y->right;
    AVL_TREE t2 = x->left;

    x->left = y;
    y->right = t2;

    y->height =  max(get_height(y->left), get_height(y->right)) + 1;
    x->height  = max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

AVL_TREE avl_insert(AVL_TREE root, int key)
{

    if(root == NULL)
        root = create_tree_node(key);
    else if(root->key > key)
        root->left = avl_insert( root->left ,key);
    else if(root->key < key)
        root->right = avl_insert(root->right ,key );
    else 
        return root;
    
    // update the height of the current new node 
    root->height = 1 + max(get_height(root->left), get_height(root->right));

    int balance_factor = get_balance_factor(root); 
    
    // left left case 
    if(balance_factor > 1 && key < root->left->key )
        return right_rotate(root);        
    
    // right right case  
    if(balance_factor < -1 && key > root->right->key)
        return left_rotate(root);

    // left right case 
    if(balance_factor > 1 && key > root->left->key){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    
    // right left case 
    if(balance_factor < -1 && key < root->right->key){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    // return the unchanged root
    return root;
}

void avl_pre_order(AVL_TREE root)
{
    if(root != NULL){
        printf("%d ",root->key);
        avl_pre_order(root->left);
        avl_pre_order(root->right);
    }
}
void avl_tree_dest(AVL_TREE T)
{
    AVL_TREE tmp = T; 
    if(tmp == NULL)
        return;
    avl_tree_dest(T->left);
    avl_tree_dest(T->right); 
    free(tmp);
}
