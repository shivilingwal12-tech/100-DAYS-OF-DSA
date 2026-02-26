/*Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("Linked list in forward order:\n");

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}