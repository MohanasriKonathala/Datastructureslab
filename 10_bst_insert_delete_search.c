#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *newNode(int x) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { puts("Memory allocation failed."); exit(1); }
    n->data = x; n->left = n->right = NULL; return n;
}
Node *insert(Node *root, int x) {
    if (!root) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    else puts("Duplicate key ignored.");
    return root;
}
Node *minimum(Node *root) { while (root && root->left) root = root->left; return root; }
Node *deleteNode(Node *root, int x) {
    if (!root) return NULL;
    if (x < root->data) root->left = deleteNode(root->left, x);
    else if (x > root->data) root->right = deleteNode(root->right, x);
    else {
        if (!root->left) { Node *r = root->right; free(root); return r; }
        if (!root->right) { Node *l = root->left; free(root); return l; }
        Node *s = minimum(root->right); root->data = s->data;
        root->right = deleteNode(root->right, s->data);
    }
    return root;
}
Node *search(Node *root, int x) {
    while (root && root->data != x) root = x < root->data ? root->left : root->right;
    return root;
}
void inorder(Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void freeTree(Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }
int main(void) {
    Node *root = NULL; int ch, x;
    do {
        printf("\n--- BST Operations ---\n1.Insert\n2.Delete\n3.Search\n4.Inorder display\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); root = insert(root, x); break;
            case 2: printf("Value to delete: "); scanf("%d", &x); if (search(root, x)) { root = deleteNode(root, x); puts("Deleted."); } else puts("Key not found."); break;
            case 3: printf("Key to search: "); scanf("%d", &x); puts(search(root, x) ? "Key found." : "Key not found."); break;
            case 4: if (!root) puts("Tree is empty."); else { inorder(root); puts(""); } break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    freeTree(root); return 0;
}
