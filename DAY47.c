/*Height of Binary Tree*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}

struct TreeNode* buildTree() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) return NULL;

    int arr[n];
    printf("Enter values in level order (-1 for NULL):\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    for (int i = 0; i < n; i++) nodes[i] = createNode(arr[i]);

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

int main() {
    struct TreeNode* root = buildTree();
    int height = maxDepth(root);
    printf("Height of Binary Tree: %d\n", height);
    return 0;
}