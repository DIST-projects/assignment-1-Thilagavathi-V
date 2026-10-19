
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* createList(int n)
{
    struct node *start = NULL;
    struct node *ptr = NULL;
    struct node *newnode;
    int data, i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        newnode = createNode(data);

        if (start == NULL)
            start = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
    }
    return start;
}

struct node *merge(struct node *a, struct node *b)
{
    struct node dummy;
    struct node *ptr = &dummy;

    dummy.next = NULL;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            ptr->next = a;
            a = a->next;
        }
        else
        {
            ptr->next = b;
            b = b->next;
        }
        ptr = ptr->next;
    }

    if (a != NULL)
        ptr->next = a;
    else
        ptr->next = b;

    return dummy.next;
}

struct node *mergeKLists(struct node *lists[], int k)
{
    struct node *result = NULL;
    int i;

    for (i = 0; i < k; i++)
        result = merge(result, lists[i]);

    return result;
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
    struct node *lists[100];
    struct node *result;
    int k, n, i;

    printf("Enter number of linked lists: ");
    scanf("%d", &k);

    if (k <= 0 || k > 100)
    {
        printf("Invalid number of lists\n");
        return 0;
    }

    for (i = 0; i < k; i++)
    {
        printf("Enter number of nodes in list %d: ", i + 1);
        scanf("%d", &n);

        if (n < 0)
        {
            printf("Invalid number of nodes\n");
            return 0;
        }

        printf("Enter sorted elements: ");
        lists[i] = createList(n);
    }

    result = mergeKLists(lists, k);

    printf("Merged sorted list: ");
    display(result);

    return 0;
}
