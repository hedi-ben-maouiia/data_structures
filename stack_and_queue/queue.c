#include "queue.h"



int is_empty(QUEUE q)
{
    return (q->q_size == 0);
}

int is_full(QUEUE q)
{
    return (q->q_size == q->max_size);
}

void make_null( QUEUE q)
{
    q->q_size = 0;
    q->front  = 1;
    q->rear   = 0;
}

size_t succ(size_t value, QUEUE q)
{
    if( ++value == q->max_size)
        value = 0;
    return value;
}

void enqueue(QUEUE q,elem_type e) 
{
   if( is_full(q) )
        fprintf(stderr,"Full Queue\n");
   else {
        q->q_size++;
        q->rear = succ( q->rear, q);
        q->arr[q->rear] = e;
    }
}
void dequeue(QUEUE aq)
{
    if(is_empty(aq)){
        fprintf(stderr,"Empty Queue\n");
    }
    else{
        for(size_t i = 0; i < aq->q_size + 1;i++){
            aq->arr[i] = aq->arr[i+1];
        }
    }
    
}
