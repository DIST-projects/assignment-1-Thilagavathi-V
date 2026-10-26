
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

struct node *deleteMiddle(struct node *start)
{
    struct node *slow, *fast;

    if (start == NULL)
        return NULL;

    if (start->next == NULL)
    {
        free(start);
        return NULL;
    }

    slow = start;
    fast = start;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->prev->next = slow->next;

    if (slow->next != NULL)
        slow->next->prev = slow->prev;

    free(slow);

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

    start = deleteMiddle(start);

    printf("After deleting middle: ");
    display(start);

    return 0;
}
