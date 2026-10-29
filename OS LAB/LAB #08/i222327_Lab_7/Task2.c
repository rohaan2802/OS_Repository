#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


void function_handler(int var)
{
    printf("\n\n\t\t\t\tPARENT RECEIVED SIGQUIT FROM CHILD! EXITING...\n\n\n");
    exit(0);
}

int main() 
{
    int pid = fork();  


    if (pid > 0) 
    {
        signal(SIGQUIT, function_handler);

        pause(); 
    }
    else
    {

        sleep(5);  
        
        kill(getppid(), SIGQUIT);

        printf("\n\n\t\t\t\tCHILD SENT SIGQUIT TO PARENT!\n");

        exit(0);
    }

    return 0;
}

