#include<stdio.h>
#include<string.h>

struct Student{
   int ID;
   char name[20];
   char grade;
};

void display(struct Student s[], int n)
{
      printf("\nSorted Students:\n");
      printf("ID\tName\tGrade\n");
    
      for (int i = 0; i < n; i++)
        printf("%d\t%s\t%c\n", s[i].ID, s[i].name, s[i].grade);
}   

void sort(struct Student s[], int n, int choice)
{
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int condition = 0;

            if ( (choice == 1 && s[i].ID > s[j].ID) ||
                 (choice == 2 && strcmp(s[i].name, s[j].name) > 0) || 
                 (choice == 3 && s[i].grade > s[j].grade) )
                condition = 1;

            if (condition)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main()
{
   int n, i, choice;

   printf("Enter number of students: ");
   scanf("%d", &n);

   struct Student s[n];

   for(i=0; i<n; i++)
   {
    printf("Enter details of student %d: \n", i+1);
    printf("ID: ");
    scanf("%d", &s[i].ID);
    printf("Name: ");
    scanf("%s", s[i].name);
    printf("Grade: ");
    scanf(" %c", &s[i].grade);
   }
   
   printf("\nSort by:\n");
   printf("1. ID\n");
   printf("2. Name\n");
   printf("3. Grade\n");
   printf("4. Exit\n");
   
   do 
   {
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      
      if (choice >= 1 && choice <= 3)
        {
            sort(s, n, choice);
            display(s, n);
        }
      else if (choice == 4)
        {
            printf("Exiting...\n");
        }
      else
        {
            printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0; 

}

