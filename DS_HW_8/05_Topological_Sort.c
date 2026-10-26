
#include <stdio.h>

int main()
{
    int n, i, j, count = 0;
    int a[20][20], indegree[20] = {0};
    int queue[20], front = 0, rear = -1;
    int topo[20], u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] == 1)
                indegree[j]++;

    for (i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;

    while (front <= rear)
    {
        u = queue[front++];
        topo[count++] = u;

        for (j = 0; j < n; j++)
        {
            if (a[u][j] == 1)
            {
                indegree[j]--;

                if (indegree[j] == 0)
                    queue[++rear] = j;
            }
        }
    }

    if (count != n)
        printf("Graph contains a cycle\n");
    else
    {
        printf("Topological order: ");

        for (i = 0; i < n; i++)
            printf("%d ", topo[i]);

        printf("\n");
    }

    return 0;
}
