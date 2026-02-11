/*Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.
*/

#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int a[x][y], b[x][y], sum[x][y];

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            sum[i][j] = a[i][j] + b[i][j];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}
