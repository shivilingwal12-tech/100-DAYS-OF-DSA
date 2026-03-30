/*Construct a binary tree from given preorder and inorder traversal arrays.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int* preIndex, int start, int end) {
    if (start > end) return NULL;

    struct Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end) return root;

    int index = findIndex(inorder, start, end, root->data);

    root->left = build(preorder, inorder, preIndex, start, index - 1);
    root->right = build(preorder, inorder, preIndex, index + 1, end);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;
    struct Node* root = build(preorder, inorder, &preIndex, 0, n - 1);

    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}