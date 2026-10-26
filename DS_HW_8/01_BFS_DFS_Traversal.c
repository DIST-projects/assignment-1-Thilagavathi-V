#include <stdio.h> 

char vertex[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
int graph[V][V] = { 
    {0, 1, 0, 1, 0, 0, 0}, // A 
    {1, 0, 0, 0, 1, 1, 0}, // B 
    {0, 0, 0, 0, 0, 1, 0}, // C 
    {1, 0, 0, 0, 0, 0, 1}, // D 
    {0, 1, 0, 0, 0, 0, 1}, // E 
    {0, 1, 1, 0, 0, 0, 1}, // F 
    {0, 0, 0, 1, 1, 1, 0}  // G 
}; 

int visited[V]; 

void BFS(int start) 
{ 
    int queue[V], front = 0, rear = 0; 
    int i, current; 
    for (i = 0; i < V; i++) 
        visited[i] = 0; 
    queue[rear++] = start; 
    visited[start] = 1; 
    while (front < rear) 
    { 
        current = queue[front++]; 
        printf("%c ", vertex[current]); 
        for (i = 0; i < V; i++) 
        { 
            if (graph[current][i] && !visited[i]) 
            { 
                queue[rear++] = i; 
                visited[i] = 1; 
            } 
        } 
    } 
} 
 
void DFS(int current) 
{ 
    int i; 
 
    visited[current] = 1; 
    printf("%c ", vertex[current]); 
 
    for (i = 0; i < V; i++) 
    { 
        if (graph[current][i] && !visited[i]) 
            DFS(i); 
    } 
} 
 
int main() 
{ 
    int i; 
 
    printf("BFS Traversal: "); 
    BFS(0); 
 
    for (i = 0; i < V; i++) 
        visited[i] = 0; 
 
    printf("\nDFS Traversal: "); 
    DFS(0); 
 
    printf("\n"); 
    return 0; 
} 