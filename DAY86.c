/*Problem: Find the integer square root of a given non-negative integer using Binary Search.
 The integer square root of a number is defined as the greatest integer whose square is less 
 than or equal to the given number.*/


 #include <stdio.h>

int main() {
    long long n, low = 0, high, mid, ans = 0;

    printf("Enter a number: ");
    scanf("%lld", &n);

    high = n;

    while (low <= high) {
        mid = (low + high) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Integer square root = %lld", ans);

    return 0;
}