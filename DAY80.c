/*Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute
 the shortest distances between every pair of vertices. The graph may contain positive or negative
 edge weights, but it does not contain any negative weight cycles.*/


#include <stdio.h>

#define INF 1000000000

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];

    printf("\nEnter adjacency matrix:\n");
    printf("(Enter -1 if there is no direct edge)\n\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Distance from %d to %d: ", i, j);
            scanf("%d", &dist[i][j]);

            if(dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}