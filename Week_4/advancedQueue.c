#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  struct node* next;
  int value;
} node_t;

typedef struct queue{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val){
    if (q == NULL){
        return -1;
    }
    if (q->size == 0){
        node_t* newNode = malloc(sizeof(node_t));
        if (newNode == NULL){
        return -1;
        }
        newNode->value = val;
        newNode->next = newNode;
        q->size++;
        q->tail = newNode;
        return 0;
    }
    node_t* newNode = malloc(sizeof(node_t));
    if (newNode == NULL){
        return -1;
    }
    newNode->value = val;
    newNode->next = q->tail->next;
    q->tail->next = newNode;
    q->size++;
    return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q){
    if (q == NULL){
        return -1;
    }
    node_t* tmpHead = q->tail->next;
    node_t* freeZone = q->tail;
    int taille = q->size;
    if  (q->size == 1){
        q->size = taille-1;
        int valueTmp = q->tail->value;
        free(freeZone);
        q->tail = NULL;
        return valueTmp;
    }
    else{
        node_t* current = q->tail->next;
        while (current->next != q->tail){
            current = current->next;
        }
        int valueTmp = q->tail->value;
        current->next = tmpHead;
        q->tail = current;
        free(freeZone);
        q->size--;
        return valueTmp;
    }
}

int main(){
    return 0;
}
