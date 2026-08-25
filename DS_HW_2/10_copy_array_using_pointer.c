#include <stdio.h>

int main()
{
    int source[100], destination[100];
    int n, i;

    int *src;
    int *dest;

    src = source;
    dest = destination;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &source[i]);

    for (i = 0; i < n; i++)
        *(dest + i) = *(src + i);

    printf("Original array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", *(src + i));

    printf("\nCopied array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", *(dest + i));

    return 0;
}