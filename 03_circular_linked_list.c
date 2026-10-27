#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *last = NULL;

Node *newNode(int x) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { puts("Memory allocation failed."); exit(1); }
    n->data = x; n->next = NULL; return n;
}
void insertBeginning(int x) {
    Node *n = newNode(x);
    if (!last) { last = n; n->next = n; }
    else { n->next = last->next; last->next = n; }
}
void insertEnd(int x) {
    Node *n = newNode(x);
    if (!last) { last = n; n->next = n; }
    else { n->next = last->next; last->next = n; last = n; }
}
void deleteValue(int x) {
    if (!last) { puts("List is empty."); return; }
    Node *prev = last, *cur = last->next;
    do {
        if (cur->data == x) {
            if (cur == prev) last = NULL;
            else {
                prev->next = cur->next;
                if (cur == last) last = prev;
            }
            free(cur); printf("Deleted %d.\n", x); return;
        }
        prev = cur; cur = cur->next;
    } while (cur != last->next);
    puts("Element not found.");
}
void display(void) {
    if (!last) { puts("List is empty."); return; }
    Node *p = last->next;
    do { printf("%d -> ", p->data); p = p->next; } while (p != last->next);
    puts("(back to head)");
}
int main(void) {
    int ch, x;
    do {
        printf("\n--- Circular Singly Linked List ---\n1.Insert beginning\n2.Insert end\n3.Delete value\n4.Display\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) return 0;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); insertBeginning(x); break;
            case 2: printf("Value: "); scanf("%d", &x); insertEnd(x); break;
            case 3: printf("Value to delete: "); scanf("%d", &x); deleteValue(x); break;
            case 4: display(); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    if (last) {
        Node *p = last->next; last->next = NULL;
        while (p) { Node *t = p; p = p->next; free(t); }
    }
    return 0;
}
