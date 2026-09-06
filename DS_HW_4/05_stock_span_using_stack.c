#include <stdio.h>

#define MAX 20

int main()
{
    int price[MAX], span[MAX], stack[MAX];
    int n, top = -1;
    int i;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter stock prices:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &price[i]);

    for (i = 0; i < n; i++)
    {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }

    printf("Stock Span:\n");
    for (i = 0; i < n; i++)
        printf("%d ", span[i]);

    return 0;
}