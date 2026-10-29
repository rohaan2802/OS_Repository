#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
pid_t p1=fork();

if(p1>0)
{
wait(NULL);
printf("\n\n\n\t\t EXECUTION COMPLETED\n\n");
}

else
{
  char *args[] = {"./child_program", NULL};
  execv(args[0], args); 
}

}
