#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>


void main() 
{
    char buffer[50];
    
    while (strcmp(buffer,"exit()")!=0)
     {
        write(1, "\n\n ENTER A MESSAGE : ", 21); 
        
     	int x =read(0, &buffer, sizeof(buffer)); 

        buffer[x-1] = '\0'; 

        write(1, "\n\n YOU ENTERED : ", 17);
        write(1, buffer, strlen(buffer));
        write(1, "\n\n", 2);
    }


}

