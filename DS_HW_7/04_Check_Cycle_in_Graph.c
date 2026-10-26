#include <stdio.h>

int graph[20][20], visited[20], n;

int hasCycle(int v, int parent) {
    int i;

    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (hasCycle(i, v))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int e, u, v, i;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &e);

    printf("Enter edges (u v):\n");

    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++) {
        if (!visited[i] && hasCycle(i, -1)) {
            printf("Cycle exists in the graph.\n");
            return 0;
        }
    }

    printf("No cycle exists in the graph.\n");
    return 0;
}