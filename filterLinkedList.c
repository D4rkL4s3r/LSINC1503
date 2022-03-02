#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    struct node *next;
    int hash;
    int id;
    char name[20];
    char buffer[100];
    unsigned int timestamp;
    char acl;
    short flow;
    char *parent;
    void *fifo;
};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head) {
        if (head == NULL){
        return NULL;
    }
    struct node* current = head;
    struct node* newHead = (struct node*) malloc(sizeof(struct node));
    if (newHead == NULL){
        return NULL;
    } 
    int count=1;
    newHead = memcpy(newHead,head,sizeof(struct node));
    struct node* newCurrent = newHead;
    newHead->next=NULL;
    current=current->next;
    while (current != NULL){
        if((count % 2) == 0){
            struct node* tmp = (struct node*) malloc(sizeof(struct node));
            if (tmp == NULL){
                return NULL;
            }
            memcpy(tmp, current, sizeof(struct node));
            tmp->next = NULL;
            newCurrent->next = tmp;
            newCurrent = newCurrent->next;
        }
        current = current->next;
        count+=1;
    }
    return newHead;
}

int main(){
    return 0;
}