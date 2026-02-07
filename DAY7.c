/*Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.*/

#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int result = fib(n);
    printf("%d", result);
    return 0;
}
