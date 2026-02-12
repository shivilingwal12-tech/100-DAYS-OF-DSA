/*Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).*/

#include <stdio.h>

int isSymmetric(int m, int n, int matrix[m][n]) {
    
    if(m != n)
        return 0;

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < n; j++) {
            if(matrix[i][j] != matrix[j][i])
                return 0;
        }
    }

    return 1;
}

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(isSymmetric(m, n, matrix))
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
