
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int coeff, exp;
    struct Node *next;
};

struct Node* insert(struct Node *start, int c, int e) 
{
    struct Node *newnode, *ptr;

    newnode = malloc(sizeof(struct Node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;

    if (start == NULL)
        return newnode;

    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = newnode;
    return start;
}

struct Node* calculate(struct Node *p, struct Node *q, int op) {
    struct Node *result = NULL;
    int c;

    while (p != NULL && q != NULL) 
    {
        if (p->exp == q->exp) 
        {
            if (op == 1)
                c = p->coeff + q->coeff;
            else
                c = p->coeff - q->coeff;

            if (c != 0)
                result = insert(result, c, p->exp);

            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp) 
        {
            result = insert(result, p->coeff, p->exp);
            p = p->next;
        }
        else 
        {
            c = q->coeff;
            if (op == 2)
                c = -c;

            result = insert(result, c, q->exp);
            q = q->next;
        }
    }

    while (p != NULL) 
    {
        result = insert(result, p->coeff, p->exp);
        p = p->next;
    }

    while (q != NULL) 
    {
        c = q->coeff;
        if (op == 2)
            c = -c;

        result = insert(result, c, q->exp);
        q = q->next;
    }

    return result;
}

void display(struct Node *start) {
    struct Node *ptr = start;

    if (ptr == NULL) 
    {
        printf("0\n");
        return;
    }

    while (ptr != NULL) 
    {
        printf("%dx^%d ", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node *p = NULL, *q = NULL;
    struct Node *sum, *diff;
    int n, i, c, e;

    printf("Enter number of terms in P1: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        p = insert(p, c, e);
    }

    printf("Enter number of terms in P2: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        q = insert(q, c, e);
    }

    sum = calculate(p, q, 1);
    diff = calculate(p, q, 2);

    printf("Addition: ");
    display(sum);

    printf("Subtraction: ");
    display(diff);

    return 0;
}
