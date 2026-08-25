#include <stdio.h>

int main()
{
    int arr[100];
    int *p;
    int n, i;

    p = arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);
    
    printf("Enter values:\n");
    for(i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    printf("\nTraversing through the array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    for (i = 0; i < n; i++)
    {
        *(p + i) = *(p + i) * 2;
    }

    printf("\n\nAfter modification:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}