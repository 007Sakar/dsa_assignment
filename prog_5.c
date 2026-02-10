#include <stdio.h>

int graph[10][10], visited[10], n;

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    int q[10], front = 0, rear = 0;
    visited[start] = 1;
    q[rear++] = start;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("DFS: ");
    DFS(0);

    for (i = 0; i < n; i++) visited[i] = 0;

    printf("\nBFS: ");
    BFS(0);
    return 0;
}
