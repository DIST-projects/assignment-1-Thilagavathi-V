
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertEnd(struct node *start, int data)
{
    struct node *newnode, *ptr;

    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
        return start;
    }
        
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
    return start;
}

struct node *insertPos(struct node *start, int data, int pos)
{
    struct node *newnode, *ptr;
    int i;

    newnode = malloc(sizeof(struct node));
    newnode->data = data;

    ptr = start;
    for (i = 1; i < pos - 1; i++)
        ptr = ptr->next;
    newnode->next = ptr->next;
    ptr->next = newnode;

    return start;
}

void checkFirstThird(struct node *start)
{
    if (start->data == start->next->next->data)
        printf("First and third elements are equal\n");
    else
        printf("First and third elements are not equal\n");
}

int main()
{
    struct node *start = NULL;
    int n, data, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("Enter at least 2 elements\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        start = insertEnd(start, data);
    }

    printf("Enter element to insert at position 3: ");
    scanf("%d", &data);
    start = insertPos(start, data, 3);

    checkFirstThird(start);

    return 0;
}
