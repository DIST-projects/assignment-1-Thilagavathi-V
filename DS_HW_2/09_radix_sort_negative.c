#include <stdio.h>

int smallest(int arr[], int n)
{
    int small = arr[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (arr[i] < small)
            small = arr[i];
    }

    return small;
}

int largest(int arr[], int n)
{
    int large = arr[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
    }

    return large;
}

void radix_sort(int arr[], int n)
{
    int bucket[10][50], bucketCount[10];
    int i, j, k, remainder;
    int divisor = 1, large, NOP = 0;
    int pass;

    large = largest(arr, n);

    while (large > 0)
    {
        NOP++;
        large = large / 10;
    }

    for (pass = 0; pass < NOP; pass++)
    {
        for (i = 0; i < 10; i++)
            bucketCount[i] = 0;

        for (i = 0; i < n; i++)
        {
            remainder = (arr[i] / divisor) % 10;

            bucket[remainder][bucketCount[remainder]] = arr[i];
            bucketCount[remainder]++;
        }

        i = 0;

        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < bucketCount[k]; j++)
            {
                arr[i] = bucket[k][j];
                i++;
            }
        }

        divisor = divisor * 10;
    }
}

int main()
{
    int arr[50];
    int n, i;
    int min, offset;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    min = smallest(arr, n);

    if (min < 0)
        offset = -min;
    else
        offset = 0;

    for (i = 0; i < n; i++)
        arr[i] = arr[i] + offset;

    radix_sort(arr, n);

    for (i = 0; i < n; i++)
        arr[i] = arr[i] - offset;

    printf("\nSorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}