// count the words in a string

#include <stdio.h>

int main()
{
    char str[100];
    int i, words = 1;

    printf("Enter sentence:\n");
    scanf("%[^\n]", str);

    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            words++;
    }

    printf("Number of words = %d", words);

    return 0;
}