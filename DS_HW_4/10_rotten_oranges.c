#include <stdio.h>

#define MAX 20

struct Cell
{
    int row;
    int col;
};

int main()
{
    int a[MAX][MAX];
    struct Cell queue[MAX * MAX];

    int m, n, i, j;
    int front = 0, rear = 0;
    int fresh = 0, time = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 2)
            {
                queue[rear].row = i;
                queue[rear].col = j;
                rear++;
            }
            else if (a[i][j] == 1)
                fresh++;
        }
    }

    while (front < rear && fresh > 0)
    {
        int count = rear - front;

        for (i = 0; i < count; i++)
        {
            int r = queue[front].row;
            int c = queue[front].col;
            
            front++;

            if (r > 0 && a[r - 1][c] == 1)
            {
                a[r - 1][c] = 2;
                fresh--;

                queue[rear].row = r - 1;
                queue[rear].col = c;
                rear++;
            }

            if (r < m - 1 && a[r + 1][c] == 1)
            {
                a[r + 1][c] = 2;
                fresh--;

                queue[rear].row = r + 1;
                queue[rear].col = c;
                rear++;
            }

            if (c > 0 && a[r][c - 1] == 1)
            {
                a[r][c - 1] = 2;
                fresh--;

                queue[rear].row = r;
                queue[rear].col = c - 1;
                rear++;
            }

            if (c < n - 1 && a[r][c + 1] == 1)
            {
                a[r][c + 1] = 2;
                fresh--;

                queue[rear].row = r;
                queue[rear].col = c + 1;
                rear++;
            }
        }

        time++;
    }

    if (fresh == 0)
        printf("Minimum time: %d", time);
    else
        printf("Minimum time: -1");

    return 0;
}