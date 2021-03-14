#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node* next;
    int order_number;
    int qty;
}order;

typedef struct {
    order *head,*tail;
    int size;
}Queue;


void enqueue(Queue *q,int ord,int qty){
   order *new_node = (order*) malloc(sizeof(order));
   if (new_node)
   {
       new_node->next=NULL;
       new_node->order_number=ord;
       new_node->qty=qty;
       if (q->head==NULL)
       {
           q->head=new_node;
       }else{
           q->tail->next=new_node;
       }
       q->tail=new_node;
       q->size++;
   }
}

int  dequeue(Queue *q){
    if (q->size==0)
    {
        printf("Not have any queue left.\n");
        return 0;
    }
    order *t=q->head;
    int value=q->head->qty;
    if (q->head->order_number == 1 )
    {
        printf("Raman\n");
        value = value*120;
    }
    else if (q->head->order_number == 2 )
    {
        printf("Sushi\n");
        value = value*60;
    }else if (q->head->order_number == 3 )
    {
        printf("Water\n");
        value = value*5;
    }
    q->head=q->head->next;
    q->size--;
    free(t);
    if (q->head==NULL)
    {
        q->tail=NULL;
    }
    return value;
}