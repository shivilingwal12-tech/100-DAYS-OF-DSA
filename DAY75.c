/*Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, max_length = 0;
    int hash[20001];

    for(int i = 0; i < 20001; i++) {
        hash[i] = -2;
    }

    hash[10000] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(hash[sum + 10000] != -2) {
            int len = i - hash[sum + 10000];
            if(len > max_length) {
                max_length = len;
            }
        } else {
            hash[sum + 10000] = i;
        }
    }

    printf("Length of longest subarray with sum 0: %d", max_length);

    return 0;
}