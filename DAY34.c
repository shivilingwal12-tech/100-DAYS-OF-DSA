/*Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){
    char exp[200];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    char* token = strtok(exp, " \n");

    while(token != NULL){
        if(isdigit(token[0])){
            push(atoi(token));
        }else{
            int b = pop();
            int a = pop();
            int res;

            if(token[0] == '+') res = a + b;
            else if(token[0] == '-') res = a - b;
            else if(token[0] == '*') res = a * b;
            else if(token[0] == '/') res = a / b;

            push(res);
        }
        token = strtok(NULL, " \n");
    }

    printf("Result: %d\n", pop());
    return 0;
}