#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX], front = 0, rear = -1;
typedef struct Node { int data; struct Node *next; } Node;
Node *qFront = NULL, *qRear = NULL;

void arrEnqueue(int x) {
    if (rear == MAX - 1) puts("Array queue is full.");
    else q[++rear] = x;
}
void arrDequeue(void) {
    if (front > rear) puts("Array queue is empty.");
    else {
        printf("Dequeued: %d\n", q[front++]);
        if (front > rear) { front = 0; rear = -1; }
    }
}
void arrDisplay(void) {
    if (front > rear) { puts("Queue is empty."); return; }
    for (int i = front; i <= rear; ++i) printf("%d ", q[i]);
    puts("");
}
void listEnqueue(int x) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { puts("Memory allocation failed."); return; }
    n->data = x; n->next = NULL;
    if (!qRear) qFront = qRear = n;
    else { qRear->next = n; qRear = n; }
}
void listDequeue(void) {
    if (!qFront) { puts("Queue is empty."); return; }
    Node *t = qFront; printf("Dequeued: %d\n", t->data);
    qFront = t->next; if (!qFront) qRear = NULL; free(t);
}
void listDisplay(void) {
    if (!qFront) { puts("Queue is empty."); return; }
    for (Node *p = qFront; p; p = p->next) printf("%d ", p->data);
    puts("");
}
int main(void) {
    int mode, ch, x;
    do {
        printf("\nImplementation: 1.Array 2.Linked list 0.Exit: ");
        if (scanf("%d", &mode) != 1 || mode == 0) break;
        if (mode != 1 && mode != 2) { puts("Invalid choice."); continue; }
        do {
            printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Back\nChoice: ");
            scanf("%d", &ch);
            if (ch == 1) {
                printf("Value: "); scanf("%d", &x);
                if (mode == 1) arrEnqueue(x); else listEnqueue(x);
            } else if (ch == 2) { if (mode == 1) arrDequeue(); else listDequeue(); }
            else if (ch == 3) { if (mode == 1) arrDisplay(); else listDisplay(); }
            else if (ch != 0) puts("Invalid choice.");
        } while (ch != 0);
    } while (mode != 0);
    while (qFront) { Node *t = qFront; qFront = qFront->next; free(t); }
    return 0;
}
