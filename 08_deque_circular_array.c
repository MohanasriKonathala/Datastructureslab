#include <stdio.h>
#define MAX 100
int dq[MAX], front = -1, rear = -1;

int isFull(void) { return (front == 0 && rear == MAX - 1) || (front == rear + 1); }
int isEmpty(void) { return front == -1; }
void insertFront(int x) {
    if (isFull()) { puts("Deque is full."); return; }
    if (isEmpty()) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    dq[front] = x;
}
void insertRear(int x) {
    if (isFull()) { puts("Deque is full."); return; }
    if (isEmpty()) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    dq[rear] = x;
}
void deleteFront(void) {
    if (isEmpty()) { puts("Deque is empty."); return; }
    printf("Deleted from front: %d\n", dq[front]);
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}
void deleteRear(void) {
    if (isEmpty()) { puts("Deque is empty."); return; }
    printf("Deleted from rear: %d\n", dq[rear]);
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
}
void display(void) {
    if (isEmpty()) { puts("Deque is empty."); return; }
    int i = front;
    printf("Deque: ");
    for (;;) { printf("%d ", dq[i]); if (i == rear) break; i = (i + 1) % MAX; }
    puts("");
}
int main(void) {
    int ch, x;
    do {
        printf("\n--- Deque using Circular Array ---\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) return 0;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); insertFront(x); break;
            case 2: printf("Value: "); scanf("%d", &x); insertRear(x); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    return 0;
}
