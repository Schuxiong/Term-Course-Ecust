#include <stdio.h> 
#define PAGE_SIZE 1024 
#define INSTRUCTIONS_PER_PAGE 10  
int main() {       
    int user_virtual_memory_size = 32 * 1024;     
    for (int user_memory_size = 4; user_memory_size <= 32; user_memory_size++) 
    {         
        int user_memory_size_bytes = user_memory_size * PAGE_SIZE;         
     int pages_to_load = user_memory_size;         
        for (int i = 0; i < 320; i++) 
        {
            int virtual_address = i * (PAGE_SIZE / INSTRUCTIONS_PER_PAGE);             
            if (virtual_address < user_memory_size_bytes)
            {                 printf("Instruction %d: Virtual Address %d (Page %d)\n", i, virtual_address, virtual_address / PAGE_SIZE);             } 
            else {                 printf("Instruction %d: Page Fault (Virtual Address %d)\n", i, virtual_address);                           }         
        }          
        printf("User Memory Size: %d pages (%d bytes)\n", user_memory_size, user_memory_size_bytes);         
        printf("----------------------------\n");     
    }      
    return 0; 
} 
