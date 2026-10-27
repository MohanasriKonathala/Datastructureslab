#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *prev, *next; } Node;
Node *head = NULL;

Node *newNode(int x) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\n"); exit(1); }
    n->data = x; n->prev = n->next = NULL; return n;
}
void insertBeginning(int x) {
    Node *n = newNode(x); n->next = head;
    if (head) head->prev = n;
    head = n;
}
void insertEnd(int x) {
    Node *n = newNode(x);
    if (!head) { head = n; return; }
    Node *p = head; while (p->next) p = p->next;
    p->next = n; n->prev = p;
}
void deleteValue(int x) {
    Node *p = head;
    while (p && p->data != x) p = p->next;
    if (!p) { printf("Element not found.\n"); return; }
    if (p->prev) p->prev->next = p->next; else head = p->next;
    if (p->next) p->next->prev = p->prev;
    free(p); printf("Deleted %d.\n", x);
}
void displayForward(void) {
    Node *p = head;
    if (!p) { printf("List is empty.\n"); return; }
    while (p) { printf("%d <-> ", p->data); p = p->next; }
    puts("NULL");
}
void displayBackward(void) {
    Node *p = head;
    if (!p) { printf("List is empty.\n"); return; }
    while (p->next) p = p->next;
    while (p) { printf("%d <-> ", p->data); p = p->prev; }
    puts("NULL");
}
int main(void) {
    int ch, x;
    do {
        printf("\n--- Doubly Linked List ---\n1.Insert beginning\n2.Insert end\n3.Delete value\n4.Display forward\n5.Display backward\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) return 0;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); insertBeginning(x); break;
            case 2: printf("Value: "); scanf("%d", &x); insertEnd(x); break;
            case 3: printf("Value to delete: "); scanf("%d", &x); deleteValue(x); break;
            case 4: displayForward(); break;
            case 5: displayBackward(); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    while (head) { Node *t = head; head = head->next; free(t); }
    return 0;
}
