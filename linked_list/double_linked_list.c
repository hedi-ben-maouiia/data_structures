#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct node*        node_ptr;
typedef struct doubly_list* dlist_ptr;

typedef struct node {
    void*       data;
    node_ptr    next;
    node_ptr    prev;
} node;
node_ptr create_node(void* data)
{
    int errnum;
    node_ptr ret = (node_ptr) malloc(sizeof(node));
    ret->data = (void*) malloc(sizeof(void*)); 
    if(NULL == ret){
        errnum = errno;
        fprintf(stderr, "ERROR: %s\n",strerror(errnum));
        exit(EXIT_FAILURE); 
    }
    memcpy(ret->data,data,8);
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}
typedef struct doubly_list {
    node_ptr head;
    node_ptr tail;
} doubly_list;
dlist_ptr create_dlist()
{
    int errnum;
    dlist_ptr dlist = (dlist_ptr) malloc(sizeof(doubly_list)); 
    if(NULL == dlist){
        errnum = errno;
        fprintf(stderr, "ERROR: %s\n",strerror(errnum));
        exit(EXIT_FAILURE); 
    }
    dlist->head = NULL;
    dlist->tail = NULL;
    return dlist;
}
void insert(dlist_ptr list,void* data)
{
    node_ptr new_node = create_node(data);  
    if(list->head == NULL){
      list->head = new_node;
      list->tail = new_node; 
    } else {
        list->tail->next =  new_node;
        new_node->prev   =  list->tail;
        list->tail       =  new_node;
    }
}

void list_dump(dlist_ptr list)
{
    node_ptr tmp = list->head;
    while(tmp){
        printf("%d ", *(int*)tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void list_dump_reverse(dlist_ptr list)
{
    node_ptr tmp = list->tail;
    while(tmp){
        printf("%d ", *(int*)tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
}

int main(void){
    dlist_ptr list;
    list = create_dlist();
    for(size_t i = 0; i < 10;++i) 
        insert(list,(int*)&i);
    list_dump(list);
    list_dump_reverse(list);
    return 0;
}
