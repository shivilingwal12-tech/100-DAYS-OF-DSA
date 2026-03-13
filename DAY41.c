/*Implement a Queue using a linked list supporting enqueue and dequeue operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void enqueue(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

int dequeue(){
    if(front==NULL) return -1;
    struct Node* temp=front;
    int val=temp->data;
    front=front->next;
    if(front==NULL) rear=NULL;
    free(temp);
    return val;
}

int main(){
    int n;
    printf("Enter number of operations: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int choice;
        printf("1.Enqueue 2.Dequeue : ");
        scanf("%d",&choice);

        if(choice==1){
            int x;
            printf("Enter value: ");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(choice==2){
            int res=dequeue();
            printf("%d\n",res);
        }
    }
}