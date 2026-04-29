/*Problem Statement Given n stalls located at different positions along a straight line and k cows,
 place the cows in the stalls such that the minimum distance between any two cows is maximized. 
 This is an optimization problem where binary search on the answer is required.*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlaceCows(int stalls[], int n, int k, int minDist)
{
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPos >= minDist)
        {
            count++;
            lastPos = stalls[i];
        }

        if (count == k)
            return 1;
    }

    return 0;
}

int aggressiveCows(int stalls[], int n, int k)
{
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, k;

    printf("Enter number of stalls: ");
    scanf("%d", &n);

    printf("Enter number of cows: ");
    scanf("%d", &k);

    int stalls[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter position of stall %d: ", i + 1);
        scanf("%d", &stalls[i]);
    }

    int result = aggressiveCows(stalls, n, k);

    printf("Maximum possible minimum distance = %d", result);

    return 0;
}