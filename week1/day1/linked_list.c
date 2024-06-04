#include <stdio.h>
#include <stdlib.h>

typedef struct node* node_ptr;
typedef struct node{
    void*        data;
    node_ptr     next; 
} node;

typedef  node_ptr List;
typedef  node_ptr Position;

List create_list()
{
    List l  = (List)malloc(sizeof(node));
    l->next = NULL;
    l->data = NULL;
    return l;
}
void dest_list(List l)
{
    free(l->next);
    free(l->data);
    free(l);
}
int is_empty(List l)
{
    return(l->next == NULL);
}

int is_last(Position p)
{
    return(p->next == NULL);
}

Position find(void* data, List l)
{
    Position p;
    p = l->next;
    while(p != NULL && l->data != data){
        p = p->next; 
    }
    return p;    
}

int main(void)
{
    List list = create_list(); 
    printf("%d\n",is_empty(list));
    dest_list(list);
    return 0;
}
