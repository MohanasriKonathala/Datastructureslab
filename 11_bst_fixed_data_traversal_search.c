#include <stdio.h>
#include <stdlib.h>

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
void inorder(Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }
int contains(Node *r, int x) { while (r) { if (x == r->data) return 1; r = x < r->data ? r->left : r->right; } return 0; }
void freeTree(Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }
int main(void) {
    int values[] = {13,3,4,12,14,10,5,1,8,2,7,9,11,6,18};
    int ch, key; Node *root = NULL;
    do {
        printf("\n--- BST: Fixed Data Set ---\n1.Create BST using given integers\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Search key\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1:
                freeTree(root); root = NULL;
                for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); ++i) root = insert(root, values[i]);
                puts("BST created using: 13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18");
                break;
            case 2: if (!root) puts("Create the BST first."); else { inorder(root); puts(""); } break;
            case 3: if (!root) puts("Create the BST first."); else { preorder(root); puts(""); } break;
            case 4: if (!root) puts("Create the BST first."); else { postorder(root); puts(""); } break;
            case 5: printf("Key: "); scanf("%d", &key); puts(contains(root, key) ? "Key found in BST." : "Key not found in BST."); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    freeTree(root); return 0;
}
