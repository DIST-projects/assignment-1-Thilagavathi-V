#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int x) {
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct node *findMin(struct node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int n, x, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter node to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("BST after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
