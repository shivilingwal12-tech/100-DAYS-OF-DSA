/*Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 && ptr2) {
        if (ptr1->data == ptr2->data)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head1, val);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        append(&head2, val);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("Intersection at node with value: %d\n", result);

    return 0;
}