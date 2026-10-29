#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int var=0;
int arr[100];
int sum=0;
int fact=1;
int count_p=0;


void *prime_num_fun(void *arg)
{

    printf("\n\n\n\t\t\t\tPRIME NUMBERS.......!\n\n\n");
    int count=0;
    int i=2;
   while(count_p!=var)
   {
         count=0;
     
        for (int j = 2; j < i; j++)
        {
        
        if(i%j==0)
        count++;    
            
        }
	
	if(count==0)
	{
	arr[count_p++]=i;
	printf("\t%d",arr[count_p-1]);
	}        
              i++;
    }

    pthread_exit(NULL);
}



void *sum_fun(void *arg)
{
    
	

 for (int i = 0; i < var; i++)
    {
        sum=sum+arr[i];
    }
    
        printf("\n\n\n\t\t\t\tSUM = %d\n\n",sum);
    pthread_exit(NULL);
}



void *factorial_fun(void *arg)
{
   
    for (int i = sum; i >=1; i--)
    {
        fact=fact*i;
    }
    
        printf("\n\n\n\t\t\t\tFACTORIAL = %d\n\n",fact);

    pthread_exit(NULL);
}

void main()
{

    pthread_t t1, t2, t3;
    

    printf("\n\n\t\t\t\tENTER THE N NUMBER:     ");
    scanf("%d",&var);

    pthread_create(&t1, NULL, prime_num_fun, NULL);
    sleep(2);
    pthread_create(&t2, NULL, sum_fun, NULL);
    sleep(2);
 
    pthread_create(&t3, NULL, factorial_fun, NULL);

    sleep(2);
    
    int final_res=fact/(count_p+1);
    printf("\n\n\t\t\t\t FINAL RESULT = %d",final_res);
    printf("\n\n\n\n");
    
}




