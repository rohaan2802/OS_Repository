#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<stdlib.h>

void main()
{
    char command[100];
    char *argv[]={command,NULL};
    
    pid_t p1= fork();
    
    if(p1>0)
     {  wait(NULL); 
        printf("\n\n\n\t\tCOMMAND EXECUTION FINISHED !....\n\n\n");
    }
    else 
     { 
        printf("ENTER A COMMAND: ");
        scanf("%s",command);
        execvp(command, argv);
     }
       
        

    
      

}

