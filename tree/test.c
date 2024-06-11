#include "binary_tree.h" // don't forget to include the library  



int main(void)
{
    // Let's make a NULL tree pointer 
    TREE root = make_null();  
    // Now let's try to insert inside root using binary_search_tree 
    root = insert(30, root);
    insert(50,root);
    insert(100,root);
    insert(60,root);
    insert(70,root);
    insert(80,root);
    insert(10,root);

    // Let's print the root tree inorder 
    printf("Root_Tree { ");
    in_order(root);
    printf("}\n");
    
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

    return 0;

}
