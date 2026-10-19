
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create(int n)
 {
    struct node *start = NULL, *ptr, *newnode;
    int i;

    for (i = 0; i < n; i++) 
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if (start == NULL) 
        {
            start = newnode;
            newnode->next = start;
        } 
        else 
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = start;
        }
    }

    return start;
}

void display(struct node *start) 
{
    struct node *ptr = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    do 
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);

    printf("\n");
}

void findPrevious(struct node *start, int target) 
{
    struct node *ptr = start;

    if (start == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    do 
    {
        if (ptr->next->data == target) 
        {
            printf("Previous node = %d\n", ptr->data);
            return;
        }
        ptr = ptr->next;
    } while (ptr != start);

    printf("Target not found\n");
}

int main() 
{
    struct node *start;
    int n, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes\n");
        return 0;
    }

    start = create(n);

    printf("Circular linked list: ");
    display(start);

    printf("Enter target value: ");
    scanf("%d", &target);

    findPrevious(start, target);

    return 0;
}
