#include <stdio.h> 
#define SIZE 7 

int main() 
{ 
    int hash[SIZE]; 
    int keys[] = {76, 93, 40, 47, 10, 55}; 
    int i, j, index; 
    
    for (i = 0; i < SIZE; i++) 
        hash[i] = -1; 
    for (i = 0; i < 6; i++) 
    { 
        index = keys[i] % SIZE; 
 
        for (j = 0; j < SIZE; j++) 
        { 
            if (hash[index] == -1) 
            { 
                hash[index] = keys[i]; 
                break; 
            } 
 
            index = (index + 1) % SIZE; 
        } 
    } 
 
    printf("Hash Table:\n"); 
    for (i = 0; i < SIZE; i++) 
        printf("%d : %d\n", i, hash[i]); 
 
    return 0; 
} 