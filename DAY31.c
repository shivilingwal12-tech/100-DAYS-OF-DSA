/*Implement a stack data structure using an array with the following operations: push, pop, and display.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op;
        printf("Enter operation (1-Push, 2-Pop, 3-Display): ");
        scanf("%d", &op);

        if (op == 1) {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        } else {
            printf("Invalid Operation\n");
        }
    }

    return 0;
}