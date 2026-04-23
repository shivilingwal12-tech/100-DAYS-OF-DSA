/*Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.*/


#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target value: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound Index: %d\n", lb);
    printf("Upper Bound Index: %d\n", ub);

    return 0;
}