
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
    int i, digit;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &digit);

        newnode = malloc(sizeof(struct node));
        newnode->data = digit;
        newnode->next = NULL;

        if (start == NULL)
            start = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
    }

    return start;
}

long long getNumber(struct node *start)
{
    long long number = 0;
    struct node *ptr = start;

    while (ptr != NULL)
    {
        number = number * 10 + ptr->data;
        ptr = ptr->next;
    }

    return number;
}

int main()
{
    struct node *list1, *list2;
    int n1, n2;
    long long num1, num2;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);

    printf("Enter digits: ");
    list1 = createList(n1);

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);

    printf("Enter digits: ");
    list2 = createList(n2);

    num1 = getNumber(list1);
    num2 = getNumber(list2);

    printf("Product = %lld\n", num1 * num2);

    return 0;
}
