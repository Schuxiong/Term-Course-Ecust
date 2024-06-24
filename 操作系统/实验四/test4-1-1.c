#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main() {     
    int instructions[320];     
    int i, m, m1, m2;     
    srand(time(NULL));     
    for (i = 0; i < 320; i += 2) 
    {         instructions[i] = i;        
     instructions[i + 1] = i + 1;     }     
    m1 = rand() % 160;      
    for (i = 0; i < 80; i++) 
    {         instructions[i] = (m1 - i) >= 0 ? (m1 - i) : 0;     }     m2 = 160 + rand() % 160;
    for (i = 160; i < 240; i++)
    {         instructions[i] = m2 + (i - 160);     }    
    for (i = 0; i < 320; i++) 
    {         int j = rand() % 320;         
     int temp = instructions[i];         
     instructions[i] = instructions[j];         
     instructions[j] = temp;     }     
    for (i = 0; i < 320; i++) {         
        printf("%d ", instructions[i]);         
        if ((i + 1) % 16 == 0) 
        {             printf("\n");         }     }      
    return 0; } 
