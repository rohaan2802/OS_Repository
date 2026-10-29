#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int x,y;
	printf("\nENTER FIRST  NUMBER   ");
	scanf("%d",&x);

	printf("\nENTER SECOND NUMBER   ");
	scanf("%d",&y);


	pid_t a=fork();
	
	/*
if(b==0)

else if(c==0)
*/
		//
		
		
if (a > 0) 
{
	wait(NULL);  
	pid_t b=fork();

	if(b>0)
	{
		wait(NULL);
		pid_t c=fork();
		
		if(c>0)
		{
		wait(NULL);
		printf("\nParent result: All child processes completed.\n\n\n");
		}
		else
		{
		printf("\nCHILD 3 RESULT (MULTIPLICATION) : %d\n\n", x*y);
		}
	}
	else
	{
	printf("\nCHILD 2 RESULT (SUBTRACTION)    : %d\n\n", x-y);
	}






}



else if (a == 0) 
{
printf("\nCHILD 1 RESULT (ADDITION)       : %d\n\n", x+y);
}
else
{
printf("\nFork failed!\n");
}

return 0;

}
