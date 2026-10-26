#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right, *nextRight;
};

struct Node *create(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = n->nextRight = NULL;
    return n;
}

void connect(struct Node *root) {
    if (!root) return;

    struct Node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear) {
        int count = rear - front;
        struct Node *prev = NULL;

        while (count--) {
            struct Node *cur = q[front++];

            if (prev)
                prev->nextRight = cur;

            prev = cur;

            if (cur->left)
                q[rear++] = cur->left;
            if (cur->right)
                q[rear++] = cur->right;
        }
        prev->nextRight = NULL;
    }
}

int main() {
    struct Node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    connect(root);

    printf("Node 2 nextRight = %d",
           root->left->nextRight->data);
    return 0;
}