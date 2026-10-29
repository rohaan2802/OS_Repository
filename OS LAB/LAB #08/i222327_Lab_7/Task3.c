#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void function_handler(int var) 
{
    
    printf("\n\n\t\t\t\tRECEIVED SIGUSR1, RESUMING EXECUTION.\n\n\n");
    exit(0);
}


int main() 
{

int pid=fork();
signal(SIGUSR1,function_handler);
sigset_t set1,set2;


if(pid>0)
{
//wait(NULL);

 sigemptyset(&set1);
 sigaddset(&set1, SIGUSR1);
 
 sigprocmask(SIG_BLOCK,&set1,&set2);
 
 printf("\n\n\t\t\t\tPARENT WAITING FOR SIGUSR1...\n");
 
 sigsuspend(&set2);  
 
 printf("\n\n\t\t\t\tRECEIVED SIGUSR1, RESUMING EXECUTION.\n");

    sigprocmask(SIG_UNBLOCK,&set1,&set2);    
       
      //  printf("\n\n\t\t\t\tCHILD PROCESS TERMINATED.\n");
}
else
{
sleep(5);
kill(getppid(), SIGUSR1);
exit(0);
}
    return 0;
}



