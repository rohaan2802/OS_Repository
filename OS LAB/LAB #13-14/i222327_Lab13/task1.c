#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t led_sem;
int toggle = 0;

void* led_on(void* arg) 
{
    while (1) 
    {
        sem_wait(&led_sem);
        if (toggle == 0) 
        {
            printf("LED ON\n");
            toggle = 1;
            sleep(1);
        }
        sem_post(&led_sem);
    }
    return NULL;
}

void* led_off(void* arg) 
{
    while (1) 
    {
        sem_wait(&led_sem);
        if (toggle == 1) 
        {
            printf("LED OFF\n");
            toggle = 0;
            sleep(1);
        }
        sem_post(&led_sem);
    }
    return NULL;
}

int main() 
{
    pthread_t t1, t2;
    sem_init(&led_sem, 0, 1);

    pthread_create(&t1, NULL, led_on, NULL);
    pthread_create(&t2, NULL, led_off, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&led_sem);
    return 0;
}

