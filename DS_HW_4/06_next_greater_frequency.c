#include <stdio.h>

#define MAX 100

int main()
{
    int a[MAX], freq[MAX] = {0}, stack[MAX], ans[MAX];    
    int n, i, j, top = -1;    

    printf("Enter number of elements: " );
    scanf("%d", &n); 

    printf("Enter elements: " );    
    for (i = 0; i < n; i++)    
      scanf("%d", &a[i]);    

    for (i = 0; i < n; i++)
        freq[a[i]]++;

    for (i = n - 1; i >= 0; i--)
    {
        while (top != -1 && freq[stack[top]] <= freq[a[i]])
            top--;

        if (top == -1)
            ans[i] = -1;
        else
            ans[i] = stack[top];

        stack[++top] = a[i];
    }

    for (i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}