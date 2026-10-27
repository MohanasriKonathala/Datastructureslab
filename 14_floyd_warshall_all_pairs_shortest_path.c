#include <stdio.h>
#define MAX 20
#define INF 10000000

int main(void) {
    int n, d[MAX][MAX];
    printf("Number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { puts("Invalid number of vertices."); return 1; }
    printf("Enter weight matrix; use %d for INF/no edge and 0 on diagonal:\n", INF);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &d[i][j]);
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    puts("All-pairs shortest-distance matrix:");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (d[i][j] >= INF) printf("INF ");
            else printf("%d ", d[i][j]);
        puts("");
    }
    return 0;
}
