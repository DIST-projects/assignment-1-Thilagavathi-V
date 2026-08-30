#include <stdio.h>

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    struct Distance d[100], sum = {0, 0};
    int n, i;

    printf("Enter number of distances: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter feet and inches for distance %d: ", i + 1);
        scanf("%d %f", &d[i].feet, &d[i].inch);

        sum.feet = sum.feet + d[i].feet;
        sum.inch = sum.inch + d[i].inch;
    }

    sum.feet += (int)(sum.inch / 12);
    sum.inch -= (int)(sum.inch / 12) * 12;

    printf("\nTotal distance = %d feet %.2f inches\n", sum.feet, sum.inch);

    return 0;
}