
#include <stdio.h>

int main()
{
    int a[100], n, key, pos = -1, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Element not found");
    }
    else
    {
        value = a[pos];

        for (int i = pos; i > 0; i--)
            a[i] = a[i - 1];

        a[0] = value;

        printf("Self-adjusted list: ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
    }

    return 0;
}
