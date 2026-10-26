#include <stdio.h>

struct Edge {
    int u, v, w;
};

struct Edge e[100], temp;
int parent[20];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main() {
    int n, m, i, j, u, v;
    int total = 0, count = 0;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < m - 1; i++) 
    {
        for (j = 0; j < m - i - 1; j++) 
        {
            if (e[j].w > e[j + 1].w) 
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    printf("Edges in MST:\n");

    for (i = 0; i < m && count < n - 1; i++) {
        u = find(e[i].u);
        v = find(e[i].v);

        if (u != v) {
            parent[u] = v;

            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);

            total += e[i].w;
            count++;
        }
    }

    if (count == n - 1)
        printf("Minimum cost: %d\n", total);
    else
        printf("Spanning tree does not exist\n");

    return 0;
}