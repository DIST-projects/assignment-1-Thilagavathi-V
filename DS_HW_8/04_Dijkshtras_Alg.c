#include <stdio.h>

#define INF 99999

int main() {
    int a[10][10], d[10], visited[10] = {0};
    int n, s, i, j, u, min;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i != j && a[i][j] == 0)
                a[i][j] = INF;
        }

    printf("Enter source: ");
    scanf("%d", &s);

    for (i = 0; i < n; i++)
        d[i] = a[s][i];

    d[s] = 0;
    visited[s] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
            if (!visited[j] && a[u][j] != INF &&
                d[u] + a[u][j] < d[j])
                d[j] = d[u] + a[u][j];
    }

    printf("Vertex\tDistance\n");
    for (i = 0; i < n; i++) {
        if (d[i] == INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, d[i]);
    }

    return 0;
}