#include <stdio.h>
#include <string.h>

#define MAX 100

char history[MAX][100];
int top = -1;

void visit(char page[])
{
    if (top == MAX - 1)
    {
       printf("History is full\n");
       return;
    }

    strcpy(history[++top], page);
    printf("Visited: %s\n", page);
}

void back()
{
    if (top == -1)
    {
       printf("No previous page\n");
       return;
    }

    printf("Going back from: %s\n", history[top]);
    top--;

    if (top >= 0)
       printf("Current page: %s\n", history[top]);
    else
       printf("No page in history\n");
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("History is empty\n");
        return;
    }

    printf("\nWeb Page History:\n");

    for (i = top; i >= 0; i--)
        printf("%s\n", history[i]);
}

int main()
{
    visit("w3schools");
    visit("YouTube");
    visit("GitHub");
    visit("Chatgpt");

    display();

    printf("\n");
    back();
    
    printf("\n");
    visit("Whatsapp");

    printf("\n");
    back();
    
    display();

    return 0;
}