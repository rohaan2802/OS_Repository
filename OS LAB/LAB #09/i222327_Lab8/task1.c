#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int arr[2][2];
int var=0;

void *transpose_fun(void *arg)
 {
    int transposed[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transposed[i][j] = arr[j][i];
        }
    }

    printf("\n\n\n\t\t\t\tTRANSPOSE.......!\n\n\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\t\t\t\t%d  ", transposed[i][j]);
        }
        printf("\n");
    }

    pthread_exit(NULL);
}



void *determinant_fun(void *arg)
{
    var = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);

    printf("\n\n\n\t\t\t\tDETERMINANT: %d\n\n", var);

    pthread_exit(NULL);
}



void *inverse_fun(void *arg)
{
   
    if (var == 0)
    {
        printf("\n\n\n\t\t\t\tINVERSE DOES NOT EXIST (DETERMINANT IS 0).\n\n\n");
        pthread_exit(NULL);
    }

    
    int adj[2][2];
    adj[0][0] = arr[1][1];
    adj[0][1] = -arr[0][1];
    adj[1][0] = -arr[1][0];
    adj[1][1] = arr[0][0];

    printf("\n\n\n\t\t\t\t ADJOINT...... \n\n");
    for (int i = 0; i < 2; i++)
     {
        for (int j = 0; j < 2; j++) 
        {
            printf("\t\t\t\t%f  ", adj[i][j] / (float)var);
        }
        printf("\n");
    }

    pthread_exit(NULL);
}

void main()
{

    pthread_t t1, t2, t3;
    

    printf("\n\n\t\t\t\tENTER THE 2X2 MATRIX:\n\n");
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\t\t\t\t");
            scanf("%d", &arr[i][j]);
        }
    }

    pthread_create(&t1, NULL, transpose_fun, NULL);
    sleep(2);
    pthread_create(&t2, NULL, determinant_fun, NULL);
    sleep(2);
 
    pthread_create(&t3, NULL, inverse_fun, NULL);

    sleep(2);
    
    printf("\n\n\n\n");
    
}


