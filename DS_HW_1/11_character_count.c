// Find no. of vowels, consonants, digits and white spaces

#include <stdio.h>

int main()
{
    char str[100];
    int i, v=0, c=0, d=0, s=0;

    printf("Enter a string:\n");
    scanf("%[^\n]", str);

    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || 
           str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            v++;

        else if((str[i]>='A' && str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
            c++;

        else if(str[i]>='0' && str[i]<='9')
            d++;

        else if(str[i]==' ')
            s++;
    }

    printf("Vowels = %d\n", v);
    printf("Consonants = %d\n", c);
    printf("Digits = %d\n", d);
    printf("White spaces = %d\n", s);

    return 0;
}