/*Construct a Binary Tree from the given level-order traversal.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int v){
    struct Node* n=malloc(sizeof(struct Node));
    n->data=v;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct Node* buildTree(int arr[],int n){
    if(n==0 || arr[0]==-1) return NULL;

    struct Node* root=newNode(arr[0]);
    struct Node* q[1000];
    int front=0,rear=0;

    q[rear++]=root;
    int i=1;

    while(i<n){
        struct Node* cur=q[front++];

        if(arr[i]!=-1){
            cur->left=newNode(arr[i]);
            q[rear++]=cur->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            cur->right=newNode(arr[i]);
            q[rear++]=cur->right;
        }
        i++;
    }

    return root;
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter level order values (-1 for NULL): ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    struct Node* root=buildTree(arr,n);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}