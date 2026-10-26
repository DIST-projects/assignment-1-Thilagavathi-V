#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node *stack[100];
int top = -1;

struct node *create(char c) {
    struct node *n = malloc(sizeof(struct node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        struct node *n = create(c);

        if (isalnum((unsigned char)c)) {
            stack[++top] = n;
        } else {
            n->right = stack[top--];
            n->left = stack[top--];
            stack[++top] = n;
        }
    }

    struct node *root = stack[top];

    printf("Expression tree created successfully\n");
    printf("Root operator: %c\n", root->data);
    printf("Left child: %c\n", root->left->data);
    printf("Right child: %c\n", root->right->data);

    return 0;
}
