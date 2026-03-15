/*Given a queue of integers, reverse the queue using a stack.*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int queue[n], stack[n];
    int front=0,rear=n-1,top=-1;

    printf("Enter queue elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&queue[i]);

    for(int i=front;i<=rear;i++)
        stack[++top]=queue[i];

    for(int i=front;i<=rear;i++)
        queue[i]=stack[top--];

    printf("Reversed queue: ");
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    return 0;
}