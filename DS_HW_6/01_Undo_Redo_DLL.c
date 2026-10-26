#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char action[50];
    struct Node *prev, *next;
};

struct Node *current = NULL;

void addAction(char s[]) {
    struct Node *n = malloc(sizeof(struct Node));
    strcpy(n->action, s);
    n->prev = current;
    n->next = NULL;

    if (current != NULL)
        current->next = n;

    current = n;
    printf("Action: %s\n", s);
}

void undo() {
    if (current == NULL || current->prev == NULL)
        printf("Cannot Undo\n");
    else {
        current = current->prev;
        printf("Undo: %s\n", current->action);
    }
}

void redo() {
    if (current == NULL || current->next == NULL)
        printf("Cannot Redo\n");
    else {
        current = current->next;
        printf("Redo: %s\n", current->action);
    }
}

int main() {
    addAction("Type A");
    addAction("Type B");
    undo();
    redo();
    return 0;
}