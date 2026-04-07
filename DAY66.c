/*Problem: Detect cycle in directed graph using DFS and recursion stack.*/

#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int** graph, int* colSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < colSize[node]; i++) {
        int nei = graph[node][i];

        if (!visited[nei] && dfs(nei, graph, colSize, visited, recStack))
            return 1;

        if (recStack[nei])
            return 1;
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int** graph = (int**)malloc(V * sizeof(int*));
    int* colSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        graph[i] = (int*)malloc(V * sizeof(int));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][colSize[u]++] = v;
    }

    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, colSize, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}