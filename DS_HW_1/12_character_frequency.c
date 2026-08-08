// Frequency of a character in a string

#include <stdio.h>

int main()
{
    char str[100];
    int freq[256] = {0}, i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    for(i = 0; str[i] != '\0'; i++)
        freq[(int)str[i]]++;

    for(i = 0; i < 256; i++)
        if(freq[i] != 0)
            printf("%c = %d\n", i, freq[i]);

    return 0;
}