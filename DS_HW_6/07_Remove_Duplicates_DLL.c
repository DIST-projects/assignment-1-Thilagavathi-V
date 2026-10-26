
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

struct node *removeDuplicatesSorted(struct node *start)
{
    struct node *ptr = start, *del;

    while (ptr != NULL && ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            del = ptr->next;
            ptr->next = del->next;

            if (del->next != NULL)
                del->next->prev = ptr;

            free(del);
        }
        else
            ptr = ptr->next;
    }

    return start;
}

struct node *removeDuplicatesUnsorted(struct node *start)
{
    struct node *ptr = start, *check, *del;

    while (ptr != NULL)
    {
        check = ptr->next;

        while (check != NULL)
        {
            if (ptr->data == check->data)
            {
                del = check;
                check = check->next;

                if (del->prev != NULL)
                    del->prev->next = del->next;

                if (del->next != NULL)
                    del->next->prev = del->prev;

                free(del);
            }
            else
                check = check->next;
        }

        ptr = ptr->next;
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
    int choice;

    printf("1. Sorted DLL\n");
    printf("2. Unsorted DLL\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    start = createList();

    printf("Original list: ");
    display(start);

    if (choice == 1)
        start = removeDuplicatesSorted(start);
    else if (choice == 2)
        start = removeDuplicatesUnsorted(start);
    else
    {
        printf("Invalid choice\n");
        return 0;
    }

    printf("After removing duplicates: ");
    display(start);

    return 0;
}
