/*Convert an infix expression to postfix notation using stack.*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

int main(){
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");

    for(int i=0;i<strlen(infix);i++){
        char c = infix[i];

        if(isalnum(c)){
            printf("%c", c);
        }
        else{
            while(top!=-1 && precedence(peek())>=precedence(c)){
                printf("%c", pop());
            }
            push(c);
        }
    }

    while(top!=-1){
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}