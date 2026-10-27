#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX], top = -1;
typedef struct Node { int data; struct Node *next; } Node;
Node *stackTop = NULL;

void arrayPush(int x) {
    if (top == MAX - 1) puts("Array stack overflow.");
    else { arr[++top] = x; puts("Pushed."); }
}
void arrayPop(void) {
    if (top == -1) puts("Array stack underflow.");
    else printf("Popped: %d\n", arr[top--]);
}
void arrayDisplay(void) {
    if (top == -1) { puts("Stack is empty."); return; }
    for (int i = top; i >= 0; --i) printf("%d\n", arr[i]);
}
void listPush(int x) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { puts("Memory allocation failed."); return; }
    n->data = x; n->next = stackTop; stackTop = n; puts("Pushed.");
}
void listPop(void) {
    if (!stackTop) { puts("Stack is empty."); return; }
    Node *t = stackTop; printf("Popped: %d\n", t->data);
    stackTop = t->next; free(t);
}
void listDisplay(void) {
    Node *p = stackTop;
    if (!p) { puts("Stack is empty."); return; }
    while (p) { printf("%d\n", p->data); p = p->next; }
}
int main(void) {
    int mode, ch, x;
    do {
        printf("\nChoose implementation: 1.Array 2.Linked list 0.Exit: ");
        if (scanf("%d", &mode) != 1 || mode == 0) break;
        if (mode != 1 && mode != 2) { puts("Invalid implementation."); continue; }
        do {
            printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n0.Back\nChoice: ");
            scanf("%d", &ch);
            if (ch == 1) {
                printf("Value: "); scanf("%d", &x);
                if (mode == 1) arrayPush(x); else listPush(x);
            } else if (ch == 2) { if (mode == 1) arrayPop(); else listPop(); }
            else if (ch == 3) {
                if (mode == 1) { if (top < 0) puts("Stack is empty."); else printf("Top: %d\n", arr[top]); }
                else { if (!stackTop) puts("Stack is empty."); else printf("Top: %d\n", stackTop->data); }
            } else if (ch == 4) { if (mode == 1) arrayDisplay(); else listDisplay(); }
            else if (ch != 0) puts("Invalid choice.");
        } while (ch != 0);
    } while (mode != 0);
    while (stackTop) { Node *t = stackTop; stackTop = stackTop->next; free(t); }
    return 0;
}
