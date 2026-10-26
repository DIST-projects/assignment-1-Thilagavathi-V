#include <stdio.h>

#define INF 99999

int main() {
    int g[20][20], dist[20], visited[20];
    int n, source, i, j, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);

            if (i != j && g[i][j] == 0)
                g[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        dist[i] = g[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && g[u][j] != INF &&
                dist[u] + g[u][j] < dist[j]) {
                dist[j] = dist[u] + g[u][j];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);

    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> %d : Unreachable\n", source, i);
        else
            printf("%d -> %d : %d\n", source, i, dist[i]);
    }

    return 0;
}