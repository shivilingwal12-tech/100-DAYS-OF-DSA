/*Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

typedef struct {
    int hd;
    struct TreeNode* node;
} Pair;

void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    Pair* queue = (Pair*)malloc(sizeof(Pair) * 2000);
    int front = 0, rear = 0;

    int minHD = 0, maxHD = 0;

    queue[rear++] = (Pair){0, root};

    int map[4001][200];
    int count[4001] = {0};

    while (front < rear) {
        Pair p = queue[front++];
        int hd = p.hd + 2000;
        struct TreeNode* node = p.node;

        map[hd][count[hd]++] = node->val;

        if (p.hd < minHD) minHD = p.hd;
        if (p.hd > maxHD) maxHD = p.hd;

        if (node->left) queue[rear++] = (Pair){p.hd - 1, node->left};
        if (node->right) queue[rear++] = (Pair){p.hd + 1, node->right};
    }

    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 2000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}