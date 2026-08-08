// Add 2 matrices of an element in a 2D matrix

#include<stdio.h>

int main() 
{
  int m1[10][10], m2[10][10], sum[10][10];
  int r, c, i, j;

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &r, &c);

  printf("Enter the Elements of Matrix 1:\n");
  for(i=0; i<r; i++)
  {
    for(j=0; j<c; j++) 
      scanf("%d", &m1[i][j]);
  }

  printf("Enter the Elements of Matrix 2:\n");
  for(i=0; i<r; i++) 
  {
    for(j=0; j<c; j++) 
      scanf("%d", &m2[i][j]);
  }

  for(i=0; i<r; i++)
  {
    for(j=0; j<c; j++) 
      sum[i][j] = m1[i][j] + m2[i][j];
  }

  printf("\nSum of Two Matrices:\n");
  for(i=0; i<r; i++)
  {
    for(j=0; j<c; j++) 
      printf("%d ", sum[i][j]);
      
      printf("\n");
  }

  return 0;
}