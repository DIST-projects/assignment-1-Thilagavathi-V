#include <stdio.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int x)
{
    if (top1 == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    stack1[++top1] = x;
}

int dequeue()
{
    int i;

    if (top2 == -1)
    {
      while (top1 != -1)
        stack2[++top2] = stack1[top1--];
    }

    if (top2 == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return stack2[top2--];
}

void display()
{
    int i;

    printf("Queue elements: ");

    for (i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    for (i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Deleted element: %d\n", dequeue());
    
    enqueue(40);
    
    printf("Deleted element: %d\n", dequeue());
    
    display();

    return 0;
}