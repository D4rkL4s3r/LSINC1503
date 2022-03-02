#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) {
    if(a == b){
        return 0;
    } else {
        return a - b;
    }
}

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) {
    node_t *current = head;
    if(current==NULL){
        (head)=(node_t)malloc(sizeof(node_t));
        if(head==NULL){
            return -1;
        }
        (head)->next = NULL;
        (head)->val =val;
        return 0;
    }
    if(cmp(current->val,val)>0){
        node_t tempo = (node_t)malloc(sizeof(node_t));
        if(tempo==NULL){
            return -1;
        }
        (head) = tempo;
        (head)->val = val;
        (*head)->next = current;
        return 0;
    }
    if(cmp(current->val,val)==0){
        return 0;
    }
    node_t *current_prev = current;
    current = current->next;
    while(current != NULL){
        if(cmp(current->val,val)==0){
            return 0;
        }
        else if(cmp(current->val,val)>0){
            node_t tmp = (node_t)malloc(sizeof(node_t));
            if(tmp ==NULL){
                return -1;
            }
            tmp->next=current_prev->next;
            tmp->val = val;
            current_prev->next = tmp;
            return 0;
        } else{
            current_prev = current;
            current = current->next;
        }
    }
    node_t tempo = (node_t)malloc(sizeof(node_t));
    if(tempo==NULL){
        return -1;
    }
    current_prev->next = tempo;
    tempo->val = val;
    tempo->next = NULL;
    return 0;
}

int main(){
    return 0;
}