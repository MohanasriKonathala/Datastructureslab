#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\n"); exit(1); }
    n->data = value; n->next = NULL;
    return n;
}

void insertBeginning(int value) {
    Node *n = createNode(value);
    n->next = head; head = n;
}
void insertEnd(int value) {
    Node *n = createNode(value);
    if (!head) { head = n; return; }
    Node *p = head;
    while (p->next) p = p->next;
    p->next = n;
}
void deleteValue(int value) {
    Node *p = head, *prev = NULL;
    while (p && p->data != value) { prev = p; p = p->next; }
    if (!p) { printf("Element not found.\n"); return; }
    if (prev) prev->next = p->next; else head = p->next;
    free(p); printf("Deleted %d.\n", value);
}
void search(int value) {
    Node *p = head; int pos = 1;
    while (p) {
        if (p->data == value) { printf("Found at position %d.\n", pos); return; }
        p = p->next; pos++;
    }
    printf("Element not found.\n");
}
void display(void) {
    Node *p = head;
    if (!p) { printf("List is empty.\n"); return; }
    while (p) { printf("%d -> ", p->data); p = p->next; }
    printf("NULL\n");
}
int main(void) {
    int ch, x;
    do {
        printf("\n--- Singly Linked List ---\n1.Insert beginning\n2.Insert end\n3.Delete value\n4.Search\n5.Display\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) return 0;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); insertBeginning(x); break;
            case 2: printf("Value: "); scanf("%d", &x); insertEnd(x); break;
            case 3: printf("Value to delete: "); scanf("%d", &x); deleteValue(x); break;
            case 4: printf("Value to search: "); scanf("%d", &x); search(x); break;
            case 5: display(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);
    while (head) { Node *t = head; head = head->next; free(t); }
    return 0;
}
