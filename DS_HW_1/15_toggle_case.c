// Toggle case of a sentence (lowercase to uppercase and vice versa)

#include <stdio.h>

int main()
{
    char str[100];
    int i;

    printf("Enter sentence:\n");
    scanf("%[^\n]", str);

    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;

        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }

    printf("After toggle:\n%s", str);

    return 0;
}
