//insert in unsorted array

#include<stdio.h>

int main() 
{
  int n, Arr[100], i, value, pos;

  printf("Enter the number of elements:");
  scanf("%d", &n);

  printf("Enter the array elements:\n");
  for(i=0; i<n; i++) 
    scanf("%d", &Arr[i]);

  printf("Enter the number to insert:");
  scanf("%d", &value);

  printf("Enter the position to insert:");
  scanf("%d", &pos);

  for(i=n; i>=pos; i--)
    Arr[i] = Arr[i-1];

  Arr[pos-1] = value;
  n++;
   
  printf("Array after insertion:\n");
  for(i=0; i<n; i++)
   printf("%d ", Arr[i]);

  return 0;

}
   