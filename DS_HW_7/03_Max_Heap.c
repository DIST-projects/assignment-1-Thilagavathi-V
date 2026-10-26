#include <stdio.h>

int heap[100], n = 0;

void insert(int value) {
    int i = n, temp;

    heap[n] = value;
    n++;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void display() {
    int i;

    printf("Max Heap: ");
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int count, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    printf("Enter elements: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &value);
        insert(value);
    }

    display();
    return 0;
}