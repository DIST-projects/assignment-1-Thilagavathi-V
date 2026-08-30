#include <stdio.h>

struct Time
{
    int hour;
    int minute;
    int second;
};

int main()
{
    struct Time t1, t2, diff;
    int sec1, sec2, difference;

    printf("Enter first time: ");
    scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);

    printf("Enter second time: ");
    scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);

    sec1 = t1.hour * 3600 + t1.minute * 60 + t1.second;
    sec2 = t2.hour * 3600 + t2.minute * 60 + t2.second;

    if(sec1 > sec2)
        difference = sec1 - sec2;
    else
        difference = sec2 - sec1;

    diff.hour = difference / 3600;
    difference = difference % 3600;

    diff.minute = difference / 60;
    diff.second = difference % 60;

    printf("Difference = %d hours %d minutes %d seconds\n", diff.hour, diff.minute, diff.second);

    return 0;
}