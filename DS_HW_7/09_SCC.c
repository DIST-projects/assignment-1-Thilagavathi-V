#include <stdio.h>

int g[20][20], t[20][20];
int visited[20], stack[20];
int n, top = -1;

void dfs1(int v) {
    int i;

    visited[v] = 1;

    for (i = 0; i < n; i++)
        if (g[v][i] && !visited[i])
            dfs1(i);

    stack[++top] = v;
}

void dfs2(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
        if (t[v][i] && !visited[i])
            dfs2(i);
}

int main() {
    int i, j, v, component = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            t[j][i] = g[i][j];
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Strongly Connected Components:\n");

    while (top != -1) {
        v = stack[top--];

        if (!visited[v]) {
            component++;
            printf("SCC %d: ", component);
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}