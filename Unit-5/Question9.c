#include <stdio.h>
#define MAX 20

int main(void) {
    int graph[MAX][MAX], visited[MAX] = {0}, queue[MAX];
    int n, i, j, start, front = 0, rear = 0, v, connected = 1;

    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%d", &graph[i][j]) != 1) return 1;

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    if (start < 0 || start >= n) { printf("Invalid start vertex.\n"); return 1; }

    visited[start] = 1; queue[rear++] = start;
    printf("BFS visit order: ");
    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1; queue[rear++] = i;
            }
        }
    }
    printf("\n");
    for (i = 0; i < n; i++) if (!visited[i]) connected = 0;
    if (!connected) printf("Graph is partially connected from this start vertex.\n");
    else printf("All vertices are reachable from the start vertex.\n");
    return 0;
}
