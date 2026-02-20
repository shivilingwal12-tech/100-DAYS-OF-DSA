/* Given an array of integers, count the number of subarrays whose sum is equal to zero.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    long long *freq = calloc(2000001, sizeof(long long));
    long long sum = 0, count = 0;
    int offset = 1000000;

    freq[offset] = 1;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        count += freq[sum + offset];
        freq[sum + offset]++;
    }

    printf("Number of subarrays with sum zero: %lld\n", count);

    free(freq);
    return 0;
}