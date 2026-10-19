#include <stdio.h>
#define MAX 20
#define INF 999999

int main(void) {
    int cost[MAX][MAX], dist[MAX], used[MAX] = {0};
    int n, source, i, j, count, u, min;

    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter weighted adjacency matrix (0 means no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) cost[i][j] = INF;
            if (i == j) cost[i][j] = 0;
        }
    }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    if (source < 0 || source >= n) { printf("Invalid source vertex.\n"); return 1; }

    for (i = 0; i < n; i++) dist[i] = cost[source][i];
    used[source] = 1;
    for (count = 1; count < n; count++) {
        min = INF; u = -1;
        for (i = 0; i < n; i++)
            if (!used[i] && dist[i] < min) { min = dist[i]; u = i; }
        if (u == -1) break;
        used[u] = 1;
        for (j = 0; j < n; j++)
            if (!used[j] && cost[u][j] != INF &&
                dist[u] != INF && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
    }

    printf("Shortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) printf("To vertex %d: Unreachable\n", i);
        else printf("To vertex %d: %d\n", i, dist[i]);
    }
    return 0;
}
