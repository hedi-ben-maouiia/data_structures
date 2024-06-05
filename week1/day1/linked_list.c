#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE    4
#define STRING_SIZE 8

typedef struct node* node_ptr;
typedef struct node{
    void*        data;
    size_t       type;
    node_ptr     next; 
} node;

node_ptr create_node(void* data,size_t type)
{
    node_ptr init = (node_ptr) malloc(sizeof(node)); 
    init->data = malloc(sizeof(type));
    if(init == NULL || init->data == NULL){
        fprintf(stderr,"Can't allocate memroy\n");
        exit(EXIT_FAILURE);
    }
    memcpy(init->data,(int*)data,type);  
    init->type = type;
    init->next = NULL;
    return init;
}
typedef struct {
    node_ptr head;
    node_ptr tail;
} List;

List* create_list()
{
    List *l = (List*) malloc(sizeof (List));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void dest_list(List *list)
{
    while(list->head != NULL){
        node_ptr to_remove = list->head;
        node_ptr next      = to_remove->next;
        free(to_remove->data); 
        free(to_remove);
        list->head = next;
    }
    free(list);    
}

int is_empty(List* l)
{
    return (l->head == NULL) ? 1 : 0;    
}

node_ptr find_previous(List* l, void* data)
{
   // TODO : find a solution for comparing the prev->data and data for both (strings, integer) values 
    node_ptr  prev = l->head;
    while(prev->next != NULL){
        prev = prev->next;
    }
    return prev; 
}

void insert(List* l, void* data, size_t type)
{
    node_ptr tmp = create_node(data,type); 
    if(l->head == NULL){
        l->head = tmp;
        l->tail = tmp;
    }else {
        l->tail->next = tmp;
        l->tail = tmp; 
    }  
}

void delete(List* l, void* data)
{
    node_ptr prev,to_remove; 
    prev = find_previous(l,data);
    if(prev->next != NULL){
        to_remove = prev->next;
        free(to_remove);
    }
}

void print_list_data(void* data,size_t type)
{    
    switch (type) {
        case 4:
            printf("%d\n",*(int*)data);  
            break;
        case 8:
            printf("%s\n",(char*)data);
            break;  
        default:
            break;
    }    
}
void list_dump(List* l)
{
    node_ptr tmp = l->head;
    
    while(tmp){
        print_list_data(tmp->data,tmp->type);
        tmp = tmp->next;
    }

}

/*
int find(void* data, List l)
{
     // TODO : find idx of the value we want ;
    return 1;
}
*/

int main(void)
{
    List *l;
    l = create_list();
    insert(l,(char*)"c",STRING_SIZE);

    for(int i = 0; i < 10;++i){
        insert(l,(int*)&i,INT_SIZE);
    }
    int x = 2340;
    insert(l,(int*)&x,INT_SIZE); 
    insert(l,(char*)"rami",STRING_SIZE); 
    insert(l,(char*)"Hedi",STRING_SIZE);
    delete(l,(int*)&x);
 
    list_dump(l); 
    dest_list(l);
    return 0;
}
