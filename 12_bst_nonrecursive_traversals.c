#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *newNode(int x) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) exit(1);
    n->data = x; n->left = n->right = NULL; return n;
}
Node *insert(Node *r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}
void inorderIter(Node *r) {
    Node *s[MAX]; int top = -1; Node *cur = r;
    while (cur || top >= 0) {
        while (cur) { if (top == MAX-1) return; s[++top] = cur; cur = cur->left; }
        cur = s[top--]; printf("%d ", cur->data); cur = cur->right;
    }
    puts("");
}
void preorderIter(Node *r) {
    if (!r) { puts("Tree is empty."); return; }
    Node *s[MAX]; int top = -1; s[++top] = r;
    while (top >= 0) {
        Node *cur = s[top--]; printf("%d ", cur->data);
        if (cur->right) s[++top] = cur->right;
        if (cur->left) s[++top] = cur->left;
    }
    puts("");
}
void postorderIter(Node *r) {
    if (!r) { puts("Tree is empty."); return; }
    Node *s1[MAX], *s2[MAX]; int t1 = -1, t2 = -1;
    s1[++t1] = r;
    while (t1 >= 0) {
        Node *cur = s1[t1--]; s2[++t2] = cur;
        if (cur->left) s1[++t1] = cur->left;
        if (cur->right) s1[++t1] = cur->right;
    }
    while (t2 >= 0) printf("%d ", s2[t2--]->data);
    puts("");
}
void freeTree(Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }
int main(void) {
    int values[] = {6,9,5,2,8,15,24,14,7,8,5,2};
    Node *root = NULL; int ch;
    do {
        printf("\n--- BST Non-recursive Traversals ---\n1.Create BST using given integers\n2.Inorder\n3.Preorder\n4.Postorder\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1:
                freeTree(root); root = NULL;
                for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); ++i) root = insert(root, values[i]);
                puts("BST created. Duplicate values are ignored.");
                break;
            case 2: if (!root) puts("Create the BST first."); else inorderIter(root); break;
            case 3: if (!root) puts("Create the BST first."); else preorderIter(root); break;
            case 4: if (!root) puts("Create the BST first."); else postorderIter(root); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    freeTree(root); return 0;
}
