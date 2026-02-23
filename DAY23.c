/*Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* node = createNode(data);
    if (head == NULL)
        return node;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first sorted list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second sorted list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    struct Node* merged = mergeLists(list1, list2);

    printf("Merged linked list:\n");
    printList(merged);

    return 0;
}