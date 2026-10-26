#include <stdio.h> 
 
#define SIZE 7 
 
int main() 
{ 
    int hash[SIZE]; 
    int keys[] = {27, 43, 69, 2, 72}; 
    int i, j, index, h1, h2; 
 
    for (i = 0; i < SIZE; i++) 
        hash[i] = -1; 
 
    for (i = 0; i < 5; i++) 
    { 
        h1 = keys[i] % SIZE; 
        h2 = 1 + (keys[i] % 5); 
 
        for (j = 0; j < SIZE; j++) 
        { 
            index = (h1 + j * h2) % SIZE; 
 
            if (hash[index] == -1) 
            { 
                hash[index] = keys[i]; 
                break; 
            } 
        } 
    } 

    printf("Hash Table:\n"); 
    for (i = 0; i < SIZE; i++) 
       printf("%d : %d\n", i, hash[i]); 
    
    return 0; 
} 