/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = INT_MAX;
        }
    }

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int count = 1; count <= n - 1; count++) {
        int min = INT_MAX, u;

        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(!visited[v] && adj[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("Shortest distances:\n");
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}