#include<stdio.h>

int main()
{
    int n, i = 0, temp, b[32];

    printf("Enter the decimal number: ");
    scanf("%d", &n);

    temp = n;
    
    if(temp == 0)
      printf("Decimal to Binary: 0\n");

    else
    {
      while(temp > 0)
      {
        b[i] = temp % 2;
        temp /= 2;
        i++;
      }
    
      printf("Decimal to Binary: ");

      while(i > 0)
      {
        i--;
        printf("%d", b[i]);
      }
    }

    printf("\nDecimal to Octal: %o\n", n);
    printf("Decimal to Hexadecimal: %x\n", n);

    return 0;
}