#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;
    
    int (*fp)(int, int);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    fp = add;
    printf("Addition of two numbers: %d\n", fp(a, b));

    fp = multiply;
    printf("Multiplication of two numbers: %d\n", fp(a, b));

    return 0;
}