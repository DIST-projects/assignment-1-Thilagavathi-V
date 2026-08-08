//print unique elements in an array

#include <stdio.h>

int main()
{
    int n, i, j, count;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Unique elements:\n");

    for(i=0; i<n; i++)
    {
        count = 0;

        for(j=0; j<n; j++)
        {
          if(arr[i] == arr[j])
              count++;
        }

        if(count == 1)
            printf("%d ", arr[i]);
    }

    return 0;
}