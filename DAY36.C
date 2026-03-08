/*Circular Queue Using Array - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}Queue;

void enqueue(Queue* q,int val){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;

    if(q->rear==NULL){
        q->front=q->rear=temp;
        temp->next=q->front;
        return;
    }

    q->rear->next=temp;
    q->rear=temp;
    q->rear->next=q->front;
}

void dequeue(Queue* q){
    if(q->front==NULL) return;

    if(q->front==q->rear){
        free(q->front);
        q->front=q->rear=NULL;
        return;
    }

    Node* temp=q->front;
    q->front=q->front->next;
    q->rear->next=q->front;
    free(temp);
}

void display(Queue* q){
    if(q->front==NULL) return;

    Node* temp=q->front;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=q->front);
}

int main(){
    int n,m,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    Queue q;
    q.front=q.rear=NULL;

    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(&q,x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        dequeue(&q);
    }

    printf("Queue elements: ");
    display(&q);

    return 0;
}