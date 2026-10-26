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
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = c;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int main() {
    char exp[100];
    int i;
    struct node *root, *left, *right;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (isalnum((unsigned char)exp[i])) {
            stack[++top] = create(exp[i]);
        } else {
            right = stack[top--];
            left = stack[top--];

            root = create(exp[i]);
            root->left = left;
            root->right = right;

            stack[++top] = root;
        }
    }

    root = stack[top];
    printf("Expression tree constructed successfully.");

    return 0;
}