
#include <stdio.h>
#define MAX 20
#define INF 9999

int parent[MAX];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int main()
{
    int n, e, i, j, u, v, w;
    int cost[MAX][MAX], eu[MAX], ev[MAX], ew[MAX];
    int visited[MAX] = {0};
    int min, a, b, total, count, temp;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &e);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (i == j) ? 0 : INF;

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        eu[i] = u;
        ev[i] = v;
        ew[i] = w;
        cost[u][v] = cost[v][u] = w;
    }

    visited[0] = 1;
    total = count = 0;

    printf("\nPrim's MST:\n");

    while (count < n - 1)
    {
        min = INF;
        a = b = -1;

        for (i = 0; i < n; i++)
            if (visited[i])
                for (j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }

        if (b == -1)
        {
            printf("Graph is disconnected\n");
            break;
        }

        printf("%d - %d : %d\n", a, b, min);
        visited[b] = 1;
        total += min;
        count++;
    }

    if (count == n - 1)
        printf("Total cost = %d\n", total);

    for (i = 0; i < e; i++)
        for (j = i + 1; j < e; j++)
            if (ew[i] > ew[j])
            {
                temp = ew[i]; ew[i] = ew[j]; ew[j] = temp;
                temp = eu[i]; eu[i] = eu[j]; eu[j] = temp;
                temp = ev[i]; ev[i] = ev[j]; ev[j] = temp;
            }

    for (i = 0; i < n; i++)
        parent[i] = i;

    total = count = 0;

    printf("\nKruskal's MST:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        u = find(eu[i]);
        v = find(ev[i]);

        if (u != v)
        {
            printf("%d - %d : %d\n", eu[i], ev[i], ew[i]);
            parent[u] = v;
            total += ew[i];
            count++;
        }
    }

    if (count == n - 1)
        printf("Total cost = %d\n", total);
    else
        printf("Graph is disconnected\n");

    return 0;
}
