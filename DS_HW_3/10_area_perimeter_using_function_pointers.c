#include <stdio.h>

float rectArea(float l, float b)
{
    return l * b;
}

float rectPerimeter(float l, float b)
{
    return 2 * (l + b);
}

float triangleArea(float base, float h)
{
    return 0.5 * base * h;
}

float trianglePerimeter(float a, float b, float c)
{
    return a + b + c;
}

int main()
{
    float l, b;
    float h, base, s2, s3;

    float (*area)(float, float);
    float (*perimeter)(float, float);
    float (*trianglePerimeterPtr)(float, float, float);

    printf("Enter length and breadth of rectangle: ");
    scanf("%f %f", &l, &b);

    area = rectArea;
    perimeter = rectPerimeter;

    printf("Rectangle Area = %.2f\n", area(l, b));
    printf("Rectangle Perimeter = %.2f\n", perimeter(l, b));

    printf("\nEnter base and height of triangle: ");
    scanf("%f %f", &base, &h);

    printf("Enter remaining sides of triangle: ");
    scanf("%f %f", &s2, &s3);

    area = triangleArea;
    trianglePerimeterPtr = trianglePerimeter;

    printf("\nTriangle Area = %.2f", area(base, h));
    printf("\nTriangle Perimeter = %.2f", trianglePerimeterPtr(base, s2, s3));

    return 0;
}