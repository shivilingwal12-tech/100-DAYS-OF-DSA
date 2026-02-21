/*Create and Traverse Singly Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("List is empty");
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements: ", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL)
        {
            printf("Memory allocation failed");
            return 0;
        }

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List elements are: ");

    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}