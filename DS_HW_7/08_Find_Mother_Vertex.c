#include <stdio.h>

int graph[20][20], visited[20], n;

void DFS(int v) {
    int i;

    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    int i, j, candidate = -1, found;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            visited[j] = 0;

        DFS(i);
        found = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            candidate = i;
            break;
        }
    }

    if (candidate != -1)
        printf("Mother Vertex: %d\n", candidate);
    else
        printf("No Mother Vertex exists.\n");

    return 0;
}