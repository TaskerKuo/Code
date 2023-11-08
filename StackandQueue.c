// implement queue  and stack using linked list
#include<stdio.h>
#include<stdlib.h>

typedef int TYPE; 

typedef struct node{
    TYPE data;
    struct node* next;
}Node;


typedef struct queue{
    Node* front;
    Node* rear;
}Queue;

Queue* creatQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isQueueEmpty(Queue* q){
    return q->front == NULL? 1:0;
}

void enqueue(Queue* q, TYPE data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    if(q->front == NULL){
        q->front = new;
        q->rear = new;
    }
    else{
        q->rear->next = new;
        q->rear = new;
    }
}

void dequeue(Queue* q){
    if(isQueueEmpty(q)) {
        printf("\nError, queue is EMPTY.");
        exit(-1);
    }
    Node* next = q->front->next;
    free(q->front);
    q->front = next;
    if(q->front == NULL) q->rear = NULL;
}

typedef struct stack{
    Node* top;
}Stack;

Stack* creatStack(){
    Stack* s = (Stack*)malloc(sizeof(Node));
    s->top = NULL;
    return s;
}

int isStackEmpty(Stack* s){
    return s->top==NULL ? 1:0;
}

void push(Stack* s, TYPE data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    if(s->top==NULL) s->top = new;
    else{
        Node* next = s->top;
        new->next = next;
        s->top = new;
    }
}

void pop(Stack* s){
    if(isStackEmpty(s)){
        printf("\nError, Stack is EMPTY.");
        exit(-1);
    }
    Node* next = s->top->next;
    free(s->top);
    s->top = next;
}

int main(){
    printf("enqueue 0~9, and then dequeue all.\n");
    Queue* q = creatQueue();
    for(int i=0; i<10; i++) enqueue(q, i);
    while (!isQueueEmpty(q)){
        printf("%d ", q->front->data);
        dequeue(q);
    }
    printf("\npush 0~9, and then pop all.\n");
    Stack* s = creatStack();
    for(int i=0; i<10; i++) push(s, i);
    while (!isStackEmpty(s)){
        printf("%d ", s->top->data);
        pop(s);
    }
    

    return 0;
}