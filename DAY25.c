/*Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, key, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    printf("Enter linked list elements: ");
    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter key to count: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    printf("Count of %d: %d\n", key, count);

    return 0;
}