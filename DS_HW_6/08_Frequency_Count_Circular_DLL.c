
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

        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            newnode->prev = start;
        }
        else
        {
            ptr = start->prev;

            newnode->next = start;
            newnode->prev = ptr;
            ptr->next = newnode;
            start->prev = newnode;
        }
    }

    return start;
}

int countFrequency(struct node *start, int key)
{
    struct node *ptr;
    int count = 0;

    if (start == NULL)
        return 0;

    ptr = start;
    do
    {
        if (ptr->data == key)
            count++;
        ptr = ptr->next;

    } while (ptr != start);

    return count;
}

int main()
{
    struct node *start;
    int key, count;

    start = createList();

    printf("Enter element to find frequency: ");
    scanf("%d", &key);

    count = countFrequency(start, key);

    printf("Frequency = %d\n", count);

    return 0;
}
