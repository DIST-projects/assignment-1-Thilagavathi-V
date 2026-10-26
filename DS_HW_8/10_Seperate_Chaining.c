
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *hashTable[SIZE];

void initialize()
{
    int i;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}

int hash(int key)
{
    return key % SIZE;
}

struct node *find(int key)
{
    int index = hash(key);
    struct node *ptr = hashTable[index];

    while (ptr != NULL)
    {
        if (ptr->data == key)
            return ptr;

        ptr = ptr->next;
    }

    return NULL;
}

void insert(int key)
{
    int index = hash(key);
    struct node *newnode;

    if (find(key) != NULL)
    {
        printf("Element already exists\n");
        return;
    }

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
        return;

    newnode->data = key;
    newnode->next = hashTable[index];
    hashTable[index] = newnode;

    printf("Inserted successfully\n");
}

void display()
{
    int i;
    struct node *ptr;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d : ", i);

        ptr = hashTable[i];

        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice, key;

    initialize();

    while (1)
    {
        printf("\n1.Insert\n2.Find\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to find: ");
                scanf("%d", &key);

                if (find(key) != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
