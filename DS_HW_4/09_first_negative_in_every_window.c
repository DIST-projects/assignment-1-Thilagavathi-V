#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX], queue[MAX];
    int n, k, i;
    int front = 0, rear = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("\nFirst negative integers: ");

    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
          queue[rear++] = i;

        if (i >= k - 1)
        {
            while (front < rear && queue[front] < i - k + 1)
              front++;

            if (front < rear)
              printf("%d ", arr[queue[front]]);
            else
              printf("0 ");
        }
    }

    return 0;
}