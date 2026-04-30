/*Problem Statement Given an array of integers where each element represents the number of
 pages in a book, and m students, allocate books such that each student gets at least one book 
 and the maximum number of pages assigned to a student is minimized. Books must be allocated in 
 contiguous order.*/

#include <stdio.h>

int isPossible(int arr[], int n, int m, int mid) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return 0;

        if (pages + arr[i] > mid) {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        } else {
            pages += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;

    printf("Enter number of books: ");
    scanf("%d", &n);

    printf("Enter number of students: ");
    scanf("%d", &m);

    int arr[n];

    printf("Enter pages in each book:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Minimum possible maximum pages = %d", allocateBooks(arr, n, m));

    return 0;
}