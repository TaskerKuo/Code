#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>

#define TYPE int

#ifdef DEBUG
#define debug(format, ...) do { printf("[%s:%d]:", __func__, __LINE__); printf(format, __VA_ARGS__);} while(0)
#else
#define debug(format, ...) ;
#endif


typedef struct node{
    TYPE data;
    struct node *next;
}Node;

Node *creatList(){
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(!tmp) exit(-1);
    tmp->next = NULL;
    return tmp;
}

int isEmpty(Node *head){
    return !head->next;
}

void insertFist(Node *head, TYPE data){
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(!tmp) {printf("Warning: Failed to insert new node.\n"); exit(-1); }
    tmp->data = data;
    tmp->next = head->next;
    head->next = tmp;
}

void insertMiddle(Node *head, int idx, TYPE data){
    Node *tmp = head;
    for(int i=0; i<idx; i++) if (!(tmp = tmp->next)) {printf("Warning: The index %d is out of the list.\n", idx); exit(-1);}
    Node *new = (Node*)malloc(sizeof(Node));
    if(!new) {printf("Warning: Failed to insert new node.\n"); exit(-1); }
    new->data = data;
    new->next = tmp->next;
    tmp->next = new;
}

void insertLast(Node *head, TYPE data){
    Node *tmp = head;
    Node *new = (Node*)malloc(sizeof(Node));
    if(!new) {printf("Warning: Failed to insert new node.\n"); exit(-1); }
    int i = 0;
    while (tmp->next) tmp = tmp->next; 
    new->data = data;
    new->next = tmp->next;
    tmp->next = new;
}

void printLinkedList(Node *head){
    int i = 0;
    printf("Print Linked List\n");
    while ((head = head->next)) printf("Node %d with data %d\n", i++, head->data);
}

void deleteFirst(Node *head){
    if(isEmpty(head)) {printf("Error, List is Empty!"); exit(-1);}
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp = head->next;
    head->next = tmp->next;
}

void deleteMiddle(Node *head, int idx){
    Node *tmp = (Node*)malloc(sizeof(Node));
    for(int i=0; i<idx; i++) if (!(head = head->next)) {printf("Warning: The index %d is out of the list.\n", idx); exit(-1);}
    tmp = head->next;
    head->next = tmp->next;
}

Node *reverseList(Node *head){
    Node *prev = head->next;
    printf("%d\n",prev->data);
    Node *tmp = prev->next;
    head = NULL;
    while(tmp){
        prev->next = head;
        head = prev;
        prev = tmp;
        tmp = tmp->next;
    }
    Node *ret = (Node*)malloc(sizeof(Node));
    prev->next = head;
    ret->next = prev;
    return ret;
}

int main(int argc, char *argv[]){
    Node *ll = creatList();
    for(int i=0; i<5;i++) insertFist(ll,i);
    //printLinkedList(ll);
    insertMiddle(ll,5,6);
    //printLinkedList(ll);
    insertLast(ll,20);
    deleteFirst(ll);
    deleteMiddle(ll,0);
    printLinkedList(ll);
    ll = reverseList(ll);
    printLinkedList(ll);
    
    return 0;
}