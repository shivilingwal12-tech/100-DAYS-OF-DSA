/*Print the nodes visible when the binary tree is viewed from the right side.*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    printf("Enter level order values (-1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    struct Node* queue[n];
    int front = 0, rear = 0;

    if (nodes[0]) queue[rear++] = nodes[0];

    printf("Right view: ");
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];
            if (i == size - 1)
                printf("%d ", curr->data);
            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }

    return 0;
}