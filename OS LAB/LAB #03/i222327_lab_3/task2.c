#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int x;
	printf("\nENTER A NUMBER   ");
	scanf("%d",&x);

	pid_t a=fork();

if (a > 0) 
{
wait(NULL);  
printf("\nPARENT RESULT : %s\n\n\n", (x % 2) ? "ODD" : "EVEN");
}
else if (a == 0) 
{
printf("\nCHILD RESULT  : %s\n\n", (x % 2) ? "ODD" : "EVEN");
}
else
{
printf("\nFork failed!\n");
}

return 0;

}
