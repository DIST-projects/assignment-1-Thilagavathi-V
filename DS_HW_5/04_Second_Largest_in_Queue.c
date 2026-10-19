
#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = data;
}

int dequeue()
{
    int data = queue[front++];

    if (front > rear)
        front = rear = -1;

    return data;
}

void secondLargest(int n)
{
    int largest, second, x;
    int found = 0;

    largest = dequeue();
    n--;

    while (n > 0)
    {
        x = dequeue();

        if (x > largest)
        {
            second = largest;
            largest = x;
            found = 1;
        }
        else if (x < largest)
        {
            if (found == 0 || x > second)
            {
                second = x;
                found = 1;
            }
        }
        n--;
    }

    if (found == 1)
        printf("Second-largest element = %d\n", second);
    else
        printf("Second-largest element does not exist\n");
}

int main()
{
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > SIZE)
    {
        printf("Invalid number of elements\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        enqueue(data);
    }

    secondLargest(n);

    return 0;
}
