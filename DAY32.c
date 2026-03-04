/*Implement push and pop operations on a stack and verify stack operations.*/

#include <stdio.h>

int main() {
    int n, m;
    int stack[1000];
    int top = -1;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (top >= 0) top--;
    }

    printf("Remaining stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}