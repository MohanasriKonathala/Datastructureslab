#include <stdio.h>
#define MAX 20

int graph[MAX][MAX], n;
void createGraph(void) {
    printf("Number of cities (1-%d): ", MAX); scanf("%d", &n);
    if (n < 1 || n > MAX) { puts("Invalid number of cities."); n = 0; return; }
    printf("Enter adjacency matrix (%d rows of %d values, 0/1):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &graph[i][j]);
}
void bfs(int start) {
    int visited[MAX] = {0}, q[MAX], front = 0, rear = 0;
    visited[start] = 1; q[rear++] = start;
    printf("BFS reachable order: ");
    while (front < rear) {
        int u = q[front++]; printf("%d ", u + 1);
        for (int v = 0; v < n; ++v)
            if (graph[u][v] && !visited[v]) { visited[v] = 1; q[rear++] = v; }
    }
    puts("");
}
void dfsVisit(int u, int visited[]) {
    visited[u] = 1; printf("%d ", u + 1);
    for (int v = 0; v < n; ++v) if (graph[u][v] && !visited[v]) dfsVisit(v, visited);
}
void dfs(int start) {
    int visited[MAX] = {0}; printf("DFS reachable order: "); dfsVisit(start, visited); puts("");
}
int main(void) {
    int ch, start;
    do {
        printf("\n--- City Graph ---\n1.Create/replace graph\n2.BFS from start city\n3.DFS from start city\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: createGraph(); break;
            case 2:
            case 3:
                if (n == 0) { puts("Create the graph first."); break; }
                printf("Starting city (1-%d): ", n); scanf("%d", &start);
                if (start < 1 || start > n) puts("Invalid start city.");
                else if (ch == 2) bfs(start - 1); else dfs(start - 1);
                break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    return 0;
}
