
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *start, int data) 
{
    struct Node *newnode, *ptr;
    newnode = malloc(sizeof(struct Node));
    newnode->data = data;

    if (start == NULL) 
    {
        newnode->next = newnode;
        return newnode;
    }
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = newnode;
    newnode->next = start;

    return start;
}

struct Node *insertPos(struct Node *start, int data, int pos) {
    struct Node *newnode, *ptr;
    int i;

    newnode = malloc(sizeof(struct Node));
    newnode->data = data;

    if (start == NULL) 
    {
        if (pos != 1) 
        {
            printf("Invalid position\n");
            free(newnode);
            return start;
        }
        newnode->next = newnode;
        return newnode;
    }

    if (pos == 1) 
    {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        newnode->next = start;
        ptr->next = newnode;

        return newnode;
    }

    ptr = start;
    for (i = 1; i < pos - 1; i++) 
    {
        if (ptr->next == start) 
        {
            printf("Invalid position\n");
            free(newnode);
            return start;
        }
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;

    return start;
}

void display(struct Node *start) 
{
    struct Node *ptr = start;

    if (start == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    do 
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);

    printf("\n");
}

int main() 
{
    struct Node *start = NULL;
    int n, i, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter data: ");
        scanf("%d", &data);
        start = insertEnd(start, data);
    }

    printf("Original list: ");
    display(start);

    printf("Enter data and position: ");
    scanf("%d%d", &data, &pos);

    if (pos < 1 || pos > n + 1) 
    {
        printf("Invalid position\n");
        return 0;
    }

    start = insertPos(start, data, pos);

    printf("Updated list: ");
    display(start);

    return 0;
}
