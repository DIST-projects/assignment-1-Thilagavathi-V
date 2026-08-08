//count the total number of duplicate elements in an array.

#include<stdio.h>

int main() {
  int n, i, j, count = 0;
    
  printf("Enter the number of elements:");
  scanf("%d", &n);

  int Arr[n];

  printf("Enter %d elements:\n", n);
  for(i=0; i<n; i++) 
    scanf("%d", &Arr[i]);

  for(i=0; i<n; i++)
  {
    for(j=i+1; j<n; j++) 
    {
      if(Arr[i] == Arr[j]) 
      {
        count++;
        break;
      }
    }
  }

  if(count == 0)
    printf("No duplicate elements\n");
  else 
    printf("Total number of duplicate elements: %d", count);

  return 0;

}