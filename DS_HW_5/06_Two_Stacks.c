
#include <stdio.h>
#define SIZE 10

int stacks[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int data)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }
    stacks[++top1] = data;
}

void push2(int data)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }
    stacks[--top2] = data;
}

void display1()
{
    int i;

    printf("Traversing Stack 1 : ");
    for (i = top1; i >= 0; i--)
        printf("%d ", stacks[i]);
    printf("\n");
}

void display2()
{
    int i;

    printf("Traversing Stack 2 : ");
    for (i = top2; i < SIZE; i++)
        printf("%d ", stacks[i]);

    printf("\n");
}

int main()
{
    int n1, n2, data, i;

    printf("Enter number of elements in Stack 1: ");
    scanf("%d", &n1);

    printf("Enter number of elements in Stack 2: ");
    scanf("%d", &n2);

    if (n1 < 0 || n2 < 0 || n1 + n2 > SIZE)
    {
        printf("Invalid number of elements\n");
        return 0;
    }

    printf("Enter Stack 1 elements:\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &data);
        push1(data);
    }

    printf("Enter Stack 2 elements:\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &data);
        push2(data);
    }

    display1();
    display2();

    return 0;
}
