#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void main()
{
pid_t p1=fork(); // FIRST PROCESS
		if(p1>0) // PARENT
		{
		wait(NULL);
		
		pid_t p2=fork(); // SECOND PROCESS 
		
			if(p2>0)
			{
			wait(NULL);
			
			pid_t p3=fork();
				
				if(p3>0)
				{
				wait(NULL);
				
					pid_t p4=fork();
					
					if(p4>0)
					{
					wait(NULL);
					printf("\n\n\t\t ALL CHILD PROCESSES COMPLETED !.....\n\n");
					}
					else  // FOURTH CHILD
					{
					 int z;
					 printf("\n\n\t\tCHILD 4: ENTER A NUMBER:   ");
					 scanf("%d",&z);
					 
					 if(z%2==0)
					 printf("\n\n\t\t CHILD 4 RESULT: EVEN   ");
					 else
					 printf("\n\n\t\t CHILD 4 RESULT: ODD    ");
					}
					
				}
				
				else	// THIRD CHILD
				{
				int x,fact=1;
				printf("\n\n\t\tCHILD 3: ENTER A NUMBER:   ");
				scanf("%d",&x);
				for(int i=1;i<x;i++)
				{
				fact=fact*i;
				}
				printf("\n\n\t\tCHILD 3: RESULT (FACTORIAL) : %d",fact);
				}
			
			}
			
			else 	//SECOND CHILD
			{
			printf("\n\n\t\tCHILD 2: HELLO WORLD\n\n"); 
			}
			
			
		
		}
		else	// FIRST CHILD
		{
		 struct tm* ptr;
   		 time_t t;
    		 t = time(NULL);
   		 ptr = localtime(&t);
    		 printf("\n\n\n\t\t CHILD 1: CURRENT DATE & TIME :  %s", asctime(ptr));
		}
}
