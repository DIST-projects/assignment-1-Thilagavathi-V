
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *createList()
{
    struct node *start = NULL, *newnode, *ptr;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (start == NULL)
            start = newnode;
        else
        {
            ptr = start;

            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
            newnode->prev = ptr;
        }
    }

    return start;
}

struct node *reverseDLL(struct node *start)
{
    struct node *ptr = start, *swap = NULL;

    while (ptr != NULL)
    {
        swap = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = swap;

        ptr = ptr->prev;
    }

    if (swap != NULL)
        start = swap->prev;

    return start;
}

void display(struct node *start)
{
    struct node *ptr = start;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main()
{
    struct node *start;

    start = createList();

    printf("Original list: ");
    display(start);

    start = reverseDLL(start);

    printf("Reversed list: ");
    display(start);

    return 0;
}

