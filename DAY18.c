/*Given an array of integers, rotate the array to the right by k positions.*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k;
    printf("Enter rotation value: ");
    scanf("%d", &k);

    k = k % n;

    printf("Rotated array:\n");
    for (int i = n - k; i < n; i++) {
        printf("%d ", a[i]);
    }
    for (int i = 0; i < n - k; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

