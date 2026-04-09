/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    int topo[MAX];

    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    if (count != n) {
        printf("Cycle detected. Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}