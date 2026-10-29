#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t p1 = fork();

    if (p1> 0) 
    {
        wait(NULL); 
        printf("\n\n\t\tCHILD PROCESS COMPLETED !....\n\n");  
    } 
    else 
    {
        printf("\n\n\t\tFILES IN DIRECTORIES :\n\n\t\t\t");
        execl("/bin/ls", "ls", NULL);
    } 
    return 0;
}

