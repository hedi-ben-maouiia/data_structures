#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-___________helper functions______________-*/

void copy_data(void* src, void* dest, data_type type)
{
    if(type == INT_SIZE)
        memcpy((int*)src, (int*)dest,sizeof(int));
   memcpy((char*)src,(char*)dest,sizeof(char) * 64); 
}

void print_list_data(void* data,data_type type)
{    
    if(type == INT_SIZE)
        printf("%d ",*(int*)data);  

    printf("%s ",(char*)data);
}

/*-_________________________________________-*/


node_ptr create_node(void* data,data_type type)
{
    node_ptr init = (node_ptr) malloc(sizeof(node)); 
    init->data = malloc(sizeof(type));
    if(init == NULL || init->data == NULL){
        fprintf(stderr,"Can't allocate memroy\n");
        exit(EXIT_FAILURE);
    }
    copy_data(init->data,data,type); 
    init->type = type;
    init->next = NULL;
    return init;
}

List list_create()
{
    List l = {
        .head = NULL,
        .tail = NULL,
    };
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
size_t check_data(node_ptr a, void* data,size_t type)
{   
    if(type == 4)
        return *(int*) data == *(int*)a->data;
    return !strcmp((char*)a->data,(char*)data);
}
node_ptr find_previous(List* l, void* data)
{
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
    List     res   = list_create();
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

int find(void* data, List* l)
{

    node_ptr tmp = l->head;
    size_t   count = 0; 
    while(tmp){
        if(check_data(tmp,data,tmp->type)){
            return  count;
        }
        tmp = tmp->next;
        count++;
    }
    return -1;
}



