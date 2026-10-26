
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *createList()
{
    struct node *start = NULL, *ptr, *newnode;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
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

struct node *swapNodes(struct node *start, int a, int b)
{
    struct node *p = start, *q = start;
    struct node *beforeP, *afterP, *beforeQ, *afterQ;

    while (p != NULL && p->data != a)
        p = p->next;

    while (q != NULL && q->data != b)
        q = q->next;

    if (p == NULL || q == NULL)
    {
        printf("Value not found\n");
        return start;
    }

    if (p == q)
        return start;

    if (p->next == q)
    {
        beforeP = p->prev;
        afterQ = q->next;

        if (beforeP != NULL)
            beforeP->next = q;
        else
            start = q;

        if (afterQ != NULL)
            afterQ->prev = p;

        q->prev = beforeP;
        q->next = p;
        p->prev = q;
        p->next = afterQ;
    }
    else if (q->next == p)
    {
        return swapNodes(start, b, a);
    }
    else
    {
        beforeP = p->prev;
        afterP = p->next;
        beforeQ = q->prev;
        afterQ = q->next;

        if (beforeP != NULL)
            beforeP->next = q;
        else
            start = q;

        if (afterP != NULL)
            afterP->prev = q;

        if (beforeQ != NULL)
            beforeQ->next = p;
        else
            start = p;

        if (afterQ != NULL)
            afterQ->prev = p;

        p->prev = beforeQ;
        p->next = afterQ;
        q->prev = beforeP;
        q->next = afterP;
    }

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
    int a, b;

    start = createList();

    printf("Original list: ");
    display(start);

    printf("Enter two values to swap: ");
    scanf("%d %d", &a, &b);

    start = swapNodes(start, a, b);

    printf("List after swapping: ");
    display(start);

    return 0;
}
