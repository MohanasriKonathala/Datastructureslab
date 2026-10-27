#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
#define EMPTY -1

typedef struct Node { int key; struct Node *next; } Node;
int linear[SIZE], quadratic[SIZE];
Node *chain[SIZE];

void init(void) {
    for (int i = 0; i < SIZE; ++i) { linear[i] = quadratic[i] = EMPTY; chain[i] = NULL; }
}
int hash(int key) { int h = key % SIZE; return h < 0 ? h + SIZE : h; }
void insertLinear(int key) {
    int h = hash(key);
    for (int i = 0; i < SIZE; ++i) {
        int j = (h + i) % SIZE;
        if (linear[j] == EMPTY) { linear[j] = key; return; }
    }
    puts("Linear table is full.");
}
void insertQuadratic(int key) {
    int h = hash(key);
    for (int i = 0; i < SIZE; ++i) {
        int j = (h + i * i) % SIZE;
        if (quadratic[j] == EMPTY) { quadratic[j] = key; return; }
    }
    puts("Quadratic probing could not find an empty slot.");
}
void insertChain(int key) {
    int h = hash(key);
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { puts("Memory allocation failed."); return; }
    n->key = key; n->next = chain[h]; chain[h] = n;
}
void displayArray(const int a[]) {
    for (int i = 0; i < SIZE; ++i)
        if (a[i] == EMPTY) printf("%2d: --\n", i); else printf("%2d: %d\n", i, a[i]);
}
void displayChain(void) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%2d: ", i);
        for (Node *p = chain[i]; p; p = p->next) printf("%d -> ", p->key);
        puts("NULL");
    }
}
int main(void) {
    int ch, key;
    init();
    do {
        printf("\n--- Hash Collision Techniques (table size %d) ---\n1.Insert key in all techniques\n2.Display linear probing\n3.Display quadratic probing\n4.Display separate chaining\n0.Exit\nChoice: ", SIZE);
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Key: "); scanf("%d", &key); insertLinear(key); insertQuadratic(key); insertChain(key); break;
            case 2: displayArray(linear); break;
            case 3: displayArray(quadratic); break;
            case 4: displayChain(); break;
            case 0: break;
            default: puts("Invalid choice.");
        }
    } while (ch != 0);
    for (int i = 0; i < SIZE; ++i) while (chain[i]) { Node *t = chain[i]; chain[i] = t->next; free(t); }
    return 0;
}
