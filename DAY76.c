/*Problem Statement
Using DFS or BFS, count number of connected components.*/


#include <stdio.h>

int visited[1001] = {0};
int adj[1001][1001] = {0};
int queue[1001];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int choice;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter 1 for DFS or 2 for BFS: ");
    scanf("%d", &choice);

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (choice == 1)
                dfs(i);
            else
                bfs(i);
            count++;
        }
    }

    printf("Connected components: %d\n", count);

    return 0;
}