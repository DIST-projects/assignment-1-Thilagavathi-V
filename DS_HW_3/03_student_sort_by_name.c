#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
};

int main()
{
    struct Student s[100], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter details of student %d:\n", i+1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(strcmp(s[i].name, s[j].name) > 0)
            {
               temp = s[i];
               s[i] = s[j];
               s[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by name:\n");
    
    printf("\nR_no\tName\n");

    for(i = 0; i < n; i++)
      printf("%d\t%s\n", s[i].roll, s[i].name);

    return 0;
}