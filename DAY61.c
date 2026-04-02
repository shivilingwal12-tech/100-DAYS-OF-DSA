/*Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.*/

#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int directed;
    printf("Enter 1 for directed graph, 0 for undirected graph: ");
    scanf("%d", &directed);

    printf("Enter the edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        if(directed == 0) {
            adj[v][u] = 1;
        }
    }

    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}