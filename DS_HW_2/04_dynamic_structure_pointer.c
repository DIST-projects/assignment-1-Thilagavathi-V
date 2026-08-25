#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[20];
    float mark;
};

int main()
{
    int n, i;
    struct Student *p;

    printf("Enter number of students: ");
    scanf("%d", &n);

    p = (struct Student *)malloc(n * sizeof(struct Student));

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &(p + i)->id);

        printf("Name: ");
        scanf("%s", (p + i)->name);

        printf("Mark: ");
        scanf("%f", &(p + i)->mark);
    }

    printf("\nStudent Details:\n");

    for (i = 0; i < n; i++)
    {
        printf("ID = %d, Name = %s, Mark = %.2f\n",
               (p + i)->id,
               (p + i)->name,
               (p + i)->mark);
    }

    for (i = 0; i < n; i++)
    {
        (p + i)->mark = (p + i)->mark + 5;
    }

    printf("\nAfter modification:\n");

    for (i = 0; i < n; i++)
    {
        printf("ID = %d, Name = %s, Mark = %.2f\n",
               (p + i)->id,
               (p + i)->name,
               (p + i)->mark);  
    }

    free(p);

    return 0;
}