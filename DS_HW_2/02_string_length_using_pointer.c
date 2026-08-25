#include <stdio.h>

int main()
{
    char str[100];
    char *p;
    int length = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    p = str;

    while (*p != '\0')
    {
        length++;
        p++;
    }

    printf("Length of the string = %d\n", length);

    return 0;
}