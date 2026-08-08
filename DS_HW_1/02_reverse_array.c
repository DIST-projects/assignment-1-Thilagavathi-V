//Read n numbers into an array & display them in reverse order

#include<stdio.h>

int main() 
{
  int A[10];
  int n, i;
  
  printf("Enter the number of Elements:");
  scanf("%d", &n);

  printf("Enter %d elements:\n", n);
  for(i=0; i<n; i++) 
   scanf("%d", &A[i]);
  
  printf("Array in Reverse Order:\n");
  for(i=n-1; i>=0; i--)
    printf("%d ", A[i]);

  return 0;

}