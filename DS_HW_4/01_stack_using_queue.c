#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void push(int x)
{
    int i, temp;

    rear++;
    queue[rear] = x;

    for (i = front; i < rear; i++)
    {
        temp = queue[i];
        queue[i] = queue[rear];
        queue[rear] = temp;
    }
}

int pop()
{
    if (rear < front)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return queue[front++];
}

int peek()
{
    if (rear < front)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return queue[front];
}

void display()
{
    int i;

    if (rear < front)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    
    display();

    printf("Popped element: %d\n", pop());

    printf("The topmost element: %d\n", peek());
    display();

    return 0;
}