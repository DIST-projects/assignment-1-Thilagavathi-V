#include <stdio.h>

int main()
{
    float arr[100];
    int n, i, j, min;
    float temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter floating point numbers:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}