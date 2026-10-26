
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList(int n)
{
    struct node *start = NULL, *ptr, *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (start == NULL)
            start = newnode;
        else
        {
            ptr = start;

            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
        }
    }

    return start;
}

struct node *intersection(struct node *l1, struct node *l2)
{
    struct node *result = NULL, *ptr = NULL, *newnode;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data == l2->data)
        {
            newnode = malloc(sizeof(struct node));
            newnode->data = l1->data;
            newnode->next = NULL;

            if (result == NULL)
                result = newnode;
            else
                ptr->next = newnode;

            ptr = newnode;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->data < l2->data)
            l1 = l1->next;
        else
            l2 = l2->next;
    }

    return result;
}

void display(struct node *start)
{
    struct node *ptr = start;

    if (ptr == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main()
{
    struct node *l1, *l2, *result;
    int n1, n2;

    printf("Enter size of L1: ");
    scanf("%d", &n1);
    printf("Enter sorted elements of L1:\n");
    l1 = createList(n1);

    printf("Enter size of L2: ");
    scanf("%d", &n2);
    printf("Enter sorted elements of L2:\n");
    l2 = createList(n2);

    result = intersection(l1, l2);

    printf("Intersection: ");
    display(result);

    return 0;
}
