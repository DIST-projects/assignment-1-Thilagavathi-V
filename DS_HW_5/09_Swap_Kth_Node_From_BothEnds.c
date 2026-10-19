
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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

        if (start == NULL)
            start = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
    }

    return start;
}

void swapKth(struct node *start, int k, int n)
{
    struct node *first = start, *second = start, *ptr;
    int i, temp;

    if (k < 1 || k > n)
    {
        printf("Invalid k\n");
        return;
    }

    for (i = 1; i < k; i++)
        first = first->next;

    for (i = 1; i < n - k + 1; i++)
        second = second->next;

    temp = first->data;
    first->data = second->data;
    second->data = temp;

    ptr = start;
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
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes\n");
        return 0;
    }

    printf("Enter elements: ");
    start = createList(n);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("List after swapping: ");
    swapKth(start, k, n);

    return 0;
}
