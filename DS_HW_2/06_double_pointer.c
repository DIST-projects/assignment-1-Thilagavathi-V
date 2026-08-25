#include<stdio.h>

int main()
{
    int num, *ptr, **pptr;

    ptr = &num;
    pptr = &ptr;

    printf("Enter the number: ");
    scanf("%d",&num);

    printf("Value of num: %d\n",num);
    printf("Value using ptr: %d\n",*ptr);
    printf("Value using pptr: %d\n",**pptr);

    printf("Address of num: %p\n", (void*)&num);
    printf("Address stored in ptr: %p\n", (void*)ptr);

    printf("Address of ptr: %p\n", (void*)&ptr);
    printf("Address stored in pptr: %p\n", (void*)pptr);

    printf("Address of pptr: %p\n", (void*)&pptr);

    return 0;
}