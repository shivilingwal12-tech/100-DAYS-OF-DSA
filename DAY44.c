/* Perform inorder, preorder, and postorder traversals of a given binary tree.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* createNode(int val){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

struct Node* buildTree(int arr[],int n,int i){
    if(i>=n || arr[i]==-1) return NULL;
    struct Node* root=createNode(arr[i]);
    root->left=buildTree(arr,n,2*i+1);
    root->right=buildTree(arr,n,2*i+2);
    return root;
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL): ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n,0);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}