#include <stdio.h>

#define MAX 100

int main()
{
    int digits[MAX], queue[MAX];
    int n, i, front = 0, rear = 0;
    int num1 = 0, num2 = 0;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    printf("Enter digits: ");
    for (i = 0; i < n; i++)
        scanf("%d", &digits[i]);

    for (i = 0; i < n - 1; i++)
    {
        int j;

        for (j = i + 1; j < n; j++)
        {
            if (digits[i] > digits[j])
            {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        queue[rear++] = digits[i];
    }

    while (front < rear)
    {
        num1 = num1 * 10 + queue[front++];

        if (front < rear)
        {
            num2 = num2 * 10 + queue[front++];
        }
    }

    printf("\nNumbers: %d and %d", num1, num2);
    printf("\nMinimum sum: %d", num1 + num2);

    return 0;
}