#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/
int pop(struct node **head, char *result){
    if (head == NULL){
        return 1;
    }
    strcpy(result, (*head)->name);
    free((*head)->name);
    struct node* tmp = (*head)->next;
    free(*head);
    *head = tmp;
    return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/
int push(struct node **head, const char *value){
    if (head == NULL){
        return 1;
    }
    struct node* newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
        return 1;
    }
    char* zoneValue = malloc(sizeof(char)*(strlen(value)+1));
    if (zoneValue == NULL){
        return 1;
    }
    newNode->name = strcpy(zoneValue, value);
    struct node** tmp = head;
    newNode->next = *tmp;
    *head = newNode;
    return 0;
}

int main(){
    return 0;
}