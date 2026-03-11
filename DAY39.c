/*Implement a Min Heap using an array where the smallest element is always at the root.*/

#include <stdio.h>
#include <string.h>

#define MAX 100000

int heap[MAX];
int size = 0;

void swap(int *a,int *b){
    int t=*a;*a=*b;*b=t;
}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i=p;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<size && heap[l]<heap[small]) small=l;
        if(r<size && heap[r]<heap[small]) small=r;
        if(small==i) break;
        swap(&heap[i], &heap[small]);
        i=small;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

int extractMin(){
    if(size==0) return -1;
    int m=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
    return m;
}

int peek(){
    if(size==0) return -1;
    return heap[0];
}

int main(){
    int n,x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter operation: ");
        scanf("%s",op);

        if(strcmp(op,"insert")==0){
            printf("Enter value: ");
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin")==0){
            printf("%d\n",extractMin());
        }
        else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }
}