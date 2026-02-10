#include <stdio.h>

#define INF 999

int main() {
    int n, cost[10][10], dist[10], visited[10] = {0};
    int i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++)
        dist[i] = cost[src][i];

    visited[src] = 1;
    dist[src] = 0;

    for (i = 1; i < n; i++) {
        int min = INF, u = -1;
        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for (j = 0; j < n; j++)
            if (!visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
    }

    printf("Shortest distances:\n");
    for (i = 0; i < n; i++)
        printf("%d -> %d\n", i, dist[i]);

    return 0;
}
