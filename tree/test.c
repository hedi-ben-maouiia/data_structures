#include "binary_tree.h" // don't forget to include the library  
#include "avl_tree.h"

void print_after_delete(TREE root,TREE to_print, int d)
{
    if(root){
        printf("Root_Tree After delete %d { ",d);
        in_order(to_print);
        printf("}\n");
    }
    else {
        printf("Sorry nothing change you try to delete wrong number\n");
    }
}

int main(void)
{
    TREE test = make_null();
    test = tree_insert(1,test);
    tree_insert(3,test);
    tree_insert(2,test);
    in_order(test);  
    printf("\n"); 
    recover_tree(test);
    in_order(test);  
    printf("\n"); 
    // Let's make a NULL tree pointer 
    printf("\n\n_________________BST TREE______________\n\n");
    TREE root = make_null();  
    // Now let's try to insert inside root using binary_search_tree 
    root = insert(30,RED, root);
    insert(50,RED,root);
    insert(100,RED,root);
    insert(60,RED,root);
    insert(70,RED,root);
    insert(80,RED,root);
    insert(10,RED,root);
    // Let's print the root tree inorder 
    in_order(root);
    
    printf("\n"); 
    // Let's delete the element X;
    int X = 50;
    root = delete(X,root);
    printf("Root_Tree After delete %d { ",X);
    in_order(root);
    printf("}\n");

    // Let's try another element 
    X = 10;
    root = delete(X,root);
    printf("Root_Tree After delete %d { ",X);
    in_order(root);
    printf("}\n");

    // Now let's try to delete element does not exist in the tree 
    X = 200;
    root = delete(X, root);
    printf("Root_Tree After delete %d { ",X);
    in_order(root);
    printf("}\n");

    // Let's find out the minimum number in the TREE 
    TREE min = find_min(root);
    printf("The minim number = [ %d ]\n",min->key);
    // Don't forget to free the tree after you done with it  
    tree_dest(test);   
    tree_dest(root); 
    // TEST for avl_tree 
    
    printf("\n\n_________________AVL TREE______________\n\n");
    AVL_TREE avl = NULL;

     avl = avl_insert(avl,10); 
     avl = avl_insert(avl,20); 
     avl = avl_insert(avl,30); 
     avl = avl_insert(avl,40); 
     avl = avl_insert(avl,50); 
     avl = avl_insert(avl,25); 
    printf("AVL_TREE { "); 
    avl_pre_order(avl);
    printf("}\n");   
    avl_tree_dest(avl);    
    return 0;

}
