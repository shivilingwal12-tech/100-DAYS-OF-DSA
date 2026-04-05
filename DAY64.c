/*Problem: Perform BFS from a given source using queue.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(struct Node* adj[], int n, int s) {
    int* visited = (int*) calloc(n, sizeof(int));
    int* queue = (int*) malloc(n * sizeof(int));
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node** adj = (struct Node**) malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(adj, n, s);

    return 0;
}