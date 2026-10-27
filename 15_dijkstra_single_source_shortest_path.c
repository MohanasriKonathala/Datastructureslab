#include <stdio.h>
#define MAX 20
#define INF 10000000

int main(void) {
    int n, source, w[MAX][MAX], dist[MAX], used[MAX] = {0};
    printf("Number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { puts("Invalid number of vertices."); return 1; }
    printf("Enter weight matrix; use %d for no edge, 0 on diagonal. Weights must be non-negative:\n", INF);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &w[i][j]);
    printf("Source vertex (1-%d): ", n);
    if (scanf("%d", &source) != 1 || source < 1 || source > n) { puts("Invalid source."); return 1; }
    for (int i = 0; i < n; ++i) dist[i] = w[source - 1][i];
    dist[source - 1] = 0; used[source - 1] = 1;
    for (int count = 1; count < n; ++count) {
        int u = -1, best = INF;
        for (int i = 0; i < n; ++i)
            if (!used[i] && dist[i] < best) { best = dist[i]; u = i; }
        if (u == -1) break;
        used[u] = 1;
        for (int v = 0; v < n; ++v)
            if (!used[v] && w[u][v] < INF && dist[u] < INF && dist[u] + w[u][v] < dist[v])
                dist[v] = dist[u] + w[u][v];
    }
    printf("Shortest distances from vertex %d:\n", source);
    for (int i = 0; i < n; ++i) {
        printf("To %d: ", i + 1);
        if (dist[i] >= INF) puts("unreachable");
        else printf("%d\n", dist[i]);
    }
    return 0;
}
