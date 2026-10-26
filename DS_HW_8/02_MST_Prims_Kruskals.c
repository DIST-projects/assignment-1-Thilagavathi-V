#include <stdio.h> 
#define MAX 100 
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
    int edgeU[MAX], edgeV[MAX], edgeW[MAX]; 
    int cost[MAX][MAX]; 
    int selected[MAX] = {0}; 
    int total, count, min, a, b, temp; 
     
    printf("Enter number of vertices and edges: "); 
    scanf("%d%d", &n, &e); 
 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            cost[i][j] = (i == j) ? 0 : INF; 
 
    printf("Enter edges (u v weight), vertices numbered 0 to %d:\n", n - 1); 
 
    for (i = 0; i < e; i++) 
    { 
        scanf("%d%d%d", &u, &v, &w); 
        edgeU[i] = u; 
        edgeV[i] = v; 
        edgeW[i] = w; 
        cost[u][v] = cost[v][u] = w; 
    } 
 
    /* Prim's Algorithm */ 
    selected[0] = 1; 
    total = 0; 
    count = 0; 
 
    printf("\nPrim's MST:\n"); 
 
    while (count < n - 1) 
    { 
        min = INF; 
        a = -1; 
        b = -1; 
 
        for (i = 0; i < n; i++) 
        { 
            if (selected[i]) 
            { 
                for (j = 0; j < n; j++) 
                { 
                    if (!selected[j] && cost[i][j] < min) 
                    { 
                        min = cost[i][j]; 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
 
        if (a == -1) 
        { 
            printf("Graph is disconnected.\n"); 
            break; 
        } 
 
        printf("%d - %d : %d\n", a, b, min); 
        selected[b] = 1; 
        total += min; 
        count++; 
    } 
 
    if (count == n - 1) 
        printf("Total cost = %d\n", total); 
 
    /* Kruskal's Algorithm */ 
    for (i = 0; i < e; i++) 
        for (j = i + 1; j < e; j++) 
            if (edgeW[i] > edgeW[j]) 
            { 
                temp = edgeW[i]; 
                edgeW[i] = edgeW[j]; 
                edgeW[j] = temp; 
 
                temp = edgeU[i]; 
                edgeU[i] = edgeU[j]; 
                edgeU[j] = temp; 
 
                temp = edgeV[i]; 
                edgeV[i] = edgeV[j]; 
                edgeV[j] = temp; 
            } 
 
    for (i = 0; i < n; i++) 
        parent[i] = i; 
 
    total = 0; 
    count = 0; 
 
    printf("\nKruskal's MST:\n"); 
 
    for (i = 0; i < e && count < n - 1; i++) 
    { 
        u = find(edgeU[i]); 
        v = find(edgeV[i]); 
 
        if (u != v) 
        { 
            printf("%d - %d : %d\n", 
                   edgeU[i], edgeV[i], edgeW[i]); 
 
            parent[u] = v; 
            total += edgeW[i]; 
            count++; 
        } 
    } 
 
    if (count == n - 1) 
        printf("Total cost = %d\n", total); 
    else 
        printf("Graph is disconnected.\n"); 
 
    return 0; 
}