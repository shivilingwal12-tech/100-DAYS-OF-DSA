/*Construct a binary tree from given inorder and postorder traversal arrays.*/

#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if(start > end)
        return NULL;

    // Take root from postorder
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    if(start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    // IMPORTANT: Right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    // Asking user input clearly
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter %d elements of inorder traversal:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter %d elements of postorder traversal:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder traversal is:\n");
    preorder(root);

    return 0;
}