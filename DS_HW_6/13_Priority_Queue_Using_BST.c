
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, priority;
    struct node *left, *right;
};

struct node *insert(struct node *root, int data, int priority)
{
    if (root == NULL) {
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = data;
        newnode->priority = priority;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if (priority < root->priority)
        root->left = insert(root->left, data, priority);
    else
        root->right = insert(root->right, data, priority);

    return root;
}

void display(struct node *root)
{
    if (root == NULL) return;

    display(root->left);
    printf("Data=%d Priority=%d\n",
           root->data, root->priority);
    display(root->right);
}

int main()
{
    struct node *root = NULL;
    int n, data, priority;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data and priority: ");
        scanf("%d %d", &data, &priority);

        root = insert(root, data, priority);
    }

    printf("Priority queue:\n");
    display(root);

    return 0;
}
