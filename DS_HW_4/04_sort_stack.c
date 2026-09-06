#include <stdio.h>

#define MAX 100

int s[MAX], t[MAX];
int top = -1, ttop = -1;

void push(int x)
{
    s[++top] = x;
}

int pop()
{
    return s[top--];
}

void sortStack()
{
    int x;

    while (top != -1)
    {
        x = pop();

        while (ttop != -1 && t[ttop] > x)
          s[++top] = t[ttop--];

        t[++ttop] = x;
    }

    while (ttop != -1)
      s[++top] = t[ttop--];
}

void display()
{
    int i;

    printf("Stack elements: ");

    for (i = top; i >= 0; i--)
        printf("%d ", s[i]);

    printf("\n");
}

int main()
{
    push(30);
    push(10);
    push(50);
    push(20);
    push(40);

    printf("Before sorting:\n");
    display();

    sortStack();

    printf("After sorting:\n");
    display();

    return 0;
}