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
    int* val1 = (int*)data;
    while(prev->next != NULL && (*val1 != *(int*)prev->next->data)){
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
        to_remove  = prev->next;
        prev->next = to_remove->next;
        free(to_remove);
    }
}

void print_list_data(void* data,size_t type)
{    
    switch (type) {
        case 4:
            printf("%d ",*(int*)data);  
            break;
        case 8:
            printf("%s ",(char*)data);
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
    printf("\n");
}
List* add_two(List* l1, List* l2)
{
    node_ptr tmp1  = l1->head;
    node_ptr tmp2  = l2->head;
    List*    res   = create_list();
    size_t   carry = 0;
    while(tmp1 != NULL || tmp2 != NULL){
        size_t   num1  = 0;
        size_t   num2  = 0;
        if(tmp1){
            num1 = *(int*)tmp1->data;
            tmp1 = tmp1->next; 
        } 
        if(tmp2){
            num2 = *(int*)tmp2->data;
            tmp2 = tmp2->next; 
        }
        int r  = num1 + num2 + carry; 
        carry = r / 10; 
        if(r >= 10){
            r %= 10;
        }
        insert(res,(int*)&r,INT_SIZE);      
    }
    if(carry){
        insert(res,(int*)&carry,INT_SIZE);
    }
     return res;
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
    List *l,*l1;/**add*/
    l  = create_list();
    l1 = create_list(); 

    for(int i = 0; i < 10;++i){
        insert(l,(int*)&i,INT_SIZE);
        insert(l1,(int*)&i,INT_SIZE);
    }
    int x = 5;
    int d = 9;
    insert(l,(int*)&x,INT_SIZE);
    delete(l,(int*)&d); 
    //add = add_two(l,l1);

    list_dump(l);
    list_dump(l1);
    //list_dump(add); 
    dest_list(l);
    dest_list(l1);
    //dest_list(add);
    return 0;
}
