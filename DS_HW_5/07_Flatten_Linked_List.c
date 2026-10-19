#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *bottom;
};

struct node *createList(int n)
{
    struct node *start = NULL, *ptr = NULL, *newnode;
    int i, data;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);

        newnode = malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->bottom = NULL;

        if (start == NULL)
            start = newnode;
        else
            ptr->bottom = newnode;

        ptr = newnode;
    }

    return start;
}

struct node *merge(struct node *a, struct node *b)
{
    struct node *start = NULL, *ptr = NULL, *small;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            small = a;
            a = a->bottom;
        }
        else
        {
            small = b;
            b = b->bottom;
        }

        if (start == NULL)
            start = small;
        else
            ptr->bottom = small;

        ptr = small;
        ptr->next = NULL;
    }

    if (a != NULL)
        ptr->bottom = a;
    else
        ptr->bottom = b;

    return start;
}

struct node *flatten(struct node *start)
{
    struct node *result;

    if (start == NULL || start->next == NULL)
        return start;

    result = flatten(start->next);

    start->next = NULL;

    return merge(start, result);
}

void display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->bottom;
    }
    printf("\n");
}

int main()
{
    struct node *start = NULL, *ptr = NULL, *newnode;
    int n, m, i;

    printf("Enter number of head nodes: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    for (i = 0; i < n; i++)
    {
        printf("Enter number of nodes in sublist %d: ", i + 1);
        scanf("%d", &m);

        if (m <= 0)
            return 0;

        printf("Enter sorted elements: ");
        newnode = createList(m);

        if (start == NULL)
            start = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
    }

    start = flatten(start);

    printf("Flattened list: ");
    display(start);

    return 0;
}