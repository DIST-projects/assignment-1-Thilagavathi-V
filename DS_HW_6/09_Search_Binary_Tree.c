
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createTree()
{
    struct node *newnode;
    int value;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    newnode = malloc(sizeof(struct node));
    newnode->data = value;

    printf("Left child of %d:\n", value);
    newnode->left = createTree();

    printf("Right child of %d:\n", value);
    newnode->right = createTree();

    return newnode;
}

int searchTree(struct node *start, int key)
{
    if (start == NULL)
        return 0;

    if (start->data == key)
        return 1;

    if (searchTree(start->left, key))
        return 1;

    return searchTree(start->right, key);
}

int main()
{
    struct node *start;
    int key;

    start = createTree();

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (searchTree(start, key))
        printf("Element found\n");
    else
        printf("Element not found\n");

    return 0;
}
