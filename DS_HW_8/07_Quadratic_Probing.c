
#include <stdio.h> 
#define SIZE 7 

int main() 
{ 
    int hash[SIZE]; 
    int keys[] = {22, 30, 50}; 
    int i, j, index; 
 
    for (i = 0; i < SIZE; i++) 
        hash[i] = -1; 
 
    for (i = 0; i < 3; i++) 
    { 
        index = keys[i] % SIZE; 
 
        for (j = 0; j < SIZE; j++) 
        { 
            index = (keys[i] % SIZE + j * j) % SIZE; 
 
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