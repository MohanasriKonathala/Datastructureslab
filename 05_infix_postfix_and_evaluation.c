#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
void infixToPostfix(const char *in, char *out) {
    char st[MAX]; int top = -1, k = 0;
    for (int i = 0; in[i]; ++i) {
        char c = in[i];
        if (isspace((unsigned char)c)) continue;
        if (isalnum((unsigned char)c)) out[k++] = c;
        else if (c == '(') st[++top] = c;
        else if (c == ')') {
            while (top >= 0 && st[top] != '(') out[k++] = st[top--];
            if (top >= 0) --top;
        } else {
            while (top >= 0 && st[top] != '(' &&
                   (precedence(st[top]) > precedence(c) ||
                   (precedence(st[top]) == precedence(c) && c != '^')))
                out[k++] = st[top--];
            st[++top] = c;
        }
    }
    while (top >= 0) if (st[top] == '(') --top; else out[k++] = st[top--];
    out[k] = '\0';
}
int evaluatePostfix(const char *s, int *ok) {
    int st[MAX], top = -1;
    for (int i = 0; s[i]; ++i) {
        char c = s[i];
        if (isspace((unsigned char)c)) continue;
        if (isdigit((unsigned char)c)) st[++top] = c - '0';
        else if (c >= 'A' && c <= 'Z') {
            int v; printf("Value for %c: ", c);
            if (scanf("%d", &v) != 1) { *ok = 0; return 0; }
            st[++top] = v;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (top < 1) { *ok = 0; return 0; }
            int b = st[top--], a = st[top--], r = 0;
            if (c == '+') r = a + b;
            else if (c == '-') r = a - b;
            else if (c == '*') r = a * b;
            else { if (b == 0) { *ok = 0; return 0; } r = a / b; }
            st[++top] = r;
        } else { *ok = 0; return 0; }
    }
    if (top != 0) { *ok = 0; return 0; }
    *ok = 1; return st[top];
}
int main(void) {
    int ch, ok; char expr[MAX], post[MAX];
    do {
        printf("\n--- Expression Operations ---\n1.Infix to postfix\n2.Evaluate postfix (single-digit operands or uppercase variables)\n0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) return 0;
        getchar();
        if (ch == 1) {
            printf("Infix expression (no spaces required): ");
            if (!fgets(expr, sizeof(expr), stdin)) break;
            expr[strcspn(expr, "\n")] = '\0';
            infixToPostfix(expr, post); printf("Postfix: %s\n", post);
        } else if (ch == 2) {
            printf("Postfix expression: ");
            if (!fgets(expr, sizeof(expr), stdin)) break;
            expr[strcspn(expr, "\n")] = '\0';
            ok = 0; int result = evaluatePostfix(expr, &ok);
            if (ok) printf("Result: %d\n", result); else puts("Invalid postfix expression or division by zero.");
        } else if (ch != 0) puts("Invalid choice.");
    } while (ch != 0);
    return 0;
}
