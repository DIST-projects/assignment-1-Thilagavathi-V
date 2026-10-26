#include <stdio.h>

int graph[20][20], color[20], n;

int isBipartite() {
    int queue[20];
    int front, rear, i, u, v;

    for (i = 0; i < n; i++)
        color[i] = -1;

    for (i = 0; i < n; i++) {
        if (color[i] != -1)
            continue;

        front = rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            u = queue[front++];

            for (v = 0; v < n; v++) {
                if (graph[u][v]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        queue[rear++] = v;
                    } else if (color[v] == color[u]) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    if (isBipartite())
        printf("Graph is Bipartite.\n");
    else
        printf("Graph is not Bipartite.\n");

    return 0;
}