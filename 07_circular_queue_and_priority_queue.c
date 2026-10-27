#include <stdio.h>
#define MAX 100

int cq[MAX], cf = -1, cr = -1;
typedef struct { int data, priority; } Item;
Item pq[MAX]; int pn = 0;

void circularEnqueue(int x) {
    if ((cr + 1) % MAX == cf) { puts("Circular queue is full."); return; }
    if (cf == -1) cf = cr = 0; else cr = (cr + 1) % MAX;
    cq[cr] = x; puts("Inserted.");
}
void circularDequeue(void) {
    if (cf == -1) { puts("Circular queue is empty."); return; }
    printf("Deleted: %d\n", cq[cf]);
    if (cf == cr) cf = cr = -1; else cf = (cf + 1) % MAX;
}
void circularDisplay(void) {
    if (cf == -1) { puts("Queue is empty."); return; }
    int i = cf;
    for (;;) { printf("%d ", cq[i]); if (i == cr) break; i = (i + 1) % MAX; }
    puts("");
}
void priorityInsert(int x, int p) {
    if (pn == MAX) { puts("Priority queue is full."); return; }
    int i = pn - 1;
    while (i >= 0 && pq[i].priority > p) { pq[i + 1] = pq[i]; --i; }
    pq[i + 1].data = x; pq[i + 1].priority = p; pn++;
    puts("Inserted (smaller number = higher priority).");
}
void priorityDelete(void) {
    if (pn == 0) { puts("Priority queue is empty."); return; }
    printf("Deleted: %d (priority %d)\n", pq[0].data, pq[0].priority);
    for (int i = 1; i < pn; ++i) pq[i - 1] = pq[i];
    pn--;
}
void priorityDisplay(void) {
    if (!pn) { puts("Priority queue is empty."); return; }
    for (int i = 0; i < pn; ++i) printf("[%d,p=%d] ", pq[i].data, pq[i].priority);
    puts("");
}
int main(void) {
    int mode, ch, x, p;
    do {
        printf("\n1.Circular Queue 2.Priority Queue 0.Exit\nChoice: ");
        if (scanf("%d", &mode) != 1 || mode == 0) break;
        if (mode == 1) {
            do {
                printf("1.Enqueue 2.Dequeue 3.Display 0.Back\nChoice: "); scanf("%d", &ch);
                if (ch == 1) { printf("Value: "); scanf("%d", &x); circularEnqueue(x); }
                else if (ch == 2) circularDequeue();
                else if (ch == 3) circularDisplay();
                else if (ch != 0) puts("Invalid choice.");
            } while (ch != 0);
        } else if (mode == 2) {
            do {
                printf("1.Insert 2.Delete highest priority 3.Display 0.Back\nChoice: "); scanf("%d", &ch);
                if (ch == 1) { printf("Value and priority: "); scanf("%d%d", &x, &p); priorityInsert(x, p); }
                else if (ch == 2) priorityDelete();
                else if (ch == 3) priorityDisplay();
                else if (ch != 0) puts("Invalid choice.");
            } while (ch != 0);
        } else puts("Invalid choice.");
    } while (mode != 0);
    return 0;
}
