/*Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char *arr[n];
    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(101 * sizeof(char));
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char *), cmp);

    int maxCount = 1, count = 1;
    char winner[101];
    strcpy(winner, arr[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(winner, arr[i - 1]);
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        strcpy(winner, arr[n - 1]);
    }

    printf("Winner: %s %d\n", winner, maxCount);

    return 0;
}