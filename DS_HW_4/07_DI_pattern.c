#include <stdio.h>
#include <string.h>

#define MAX 20

int main()
{
    char pattern[MAX];
    int stack[MAX];
    int top = -1, num = 1, n, i;

    printf("Enter pattern: ");
    scanf("%s", pattern);

    n = strlen(pattern);

    for (i = 0; i <= n; i++)
    {
        stack[++top] = num++;

        if (i == n || pattern[i] == 'I')
        {
            while (top != -1)
            {
                printf("%d", stack[top--]);
            }
        }
    }

    return 0;
}