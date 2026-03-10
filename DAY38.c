/*A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
}Deque;

Deque* createDeque(int cap){
    Deque* dq = malloc(sizeof(Deque));
    dq->arr = malloc(sizeof(int)*cap);
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
    dq->capacity = cap;
    return dq;
}

int empty(Deque* dq){
    return dq->size==0;
}

int sizeDeque(Deque* dq){
    return dq->size;
}

void push_front(Deque* dq,int x){
    if(dq->size==dq->capacity) return;

    if(dq->front==-1){
        dq->front=0;
        dq->rear=0;
    }
    else if(dq->front==0)
        dq->front=dq->capacity-1;
    else
        dq->front--;

    dq->arr[dq->front]=x;
    dq->size++;
}

void push_back(Deque* dq,int x){
    if(dq->size==dq->capacity) return;

    if(dq->front==-1){
        dq->front=0;
        dq->rear=0;
    }
    else if(dq->rear==dq->capacity-1)
        dq->rear=0;
    else
        dq->rear++;

    dq->arr[dq->rear]=x;
    dq->size++;
}

void pop_front(Deque* dq){
    if(empty(dq)) return;

    if(dq->front==dq->rear){
        dq->front=-1;
        dq->rear=0;
    }
    else if(dq->front==dq->capacity-1)
        dq->front=0;
    else
        dq->front++;

    dq->size--;
}

void pop_back(Deque* dq){
    if(empty(dq)) return;

    if(dq->front==dq->rear){
        dq->front=-1;
        dq->rear=0;
    }
    else if(dq->rear==0)
        dq->rear=dq->capacity-1;
    else
        dq->rear--;

    dq->size--;
}

int frontVal(Deque* dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->front];
}

int backVal(Deque* dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void clear(Deque* dq){
    dq->front=-1;
    dq->rear=0;
    dq->size=0;
}

void display(Deque* dq){
    if(empty(dq)){
        printf("Deque is empty\n");
        return;
    }
    int i=dq->front;
    for(int c=0;c<dq->size;c++){
        printf("%d ",dq->arr[i]);
        i=(i+1)%dq->capacity;
    }
    printf("\n");
}

int main(){
    Deque* dq=createDeque(100);
    int choice,x;

    while(1){
        printf("\n1 push_front\n2 push_back\n3 pop_front\n4 pop_back\n5 front\n6 back\n7 empty\n8 size\n9 clear\n10 display\n11 exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                push_front(dq,x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                push_back(dq,x);
                break;
            case 3:
                pop_front(dq);
                break;
            case 4:
                pop_back(dq);
                break;
            case 5:
                printf("%d\n",frontVal(dq));
                break;
            case 6:
                printf("%d\n",backVal(dq));
                break;
            case 7:
                printf("%d\n",empty(dq));
                break;
            case 8:
                printf("%d\n",sizeDeque(dq));
                break;
            case 9:
                clear(dq);
                break;
            case 10:
                display(dq);
                break;
            case 11:
                return 0;
        }
    }
}