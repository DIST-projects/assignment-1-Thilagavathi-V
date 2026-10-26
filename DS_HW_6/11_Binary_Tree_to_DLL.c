
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *head = NULL, *prev = NULL;

struct Node *create(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void convert(struct Node *root) {
    if (!root) return;

    convert(root->left);

    if (prev == NULL)
        head = root;
    else {
        prev->right = root;
        root->left = prev;
    }

    prev = root;
    convert(root->right);
}

void display() {
    struct Node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->right;
    }
}

int main() {
    struct Node *root = create(20);
    root->left = create(10);
    root->right = create(30);

    convert(root);
    display();
    return 0;
}