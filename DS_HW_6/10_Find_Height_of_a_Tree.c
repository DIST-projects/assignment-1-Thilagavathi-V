
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

int findHeight(struct node *start)
{
    int leftHeight, rightHeight;

    if (start == NULL)
        return 0;

    leftHeight = findHeight(start->left);
    rightHeight = findHeight(start->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main()
{
    struct node *start;
    int height;

    start = createTree();

    height = findHeight(start);

    printf("Height of tree = %d\n", height);

    return 0;
}
