#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t login_sem;

void* verify_username(void* arg) 
{
    printf("Verifying username...\n");
    sleep(1);
    printf("Username verified.\n");
    sem_post(&login_sem);  
    return NULL;
}

void* verify_password(void* arg) 
{
    sem_wait(&login_sem);  
    printf("Verifying password...\n");
    sleep(1);
    printf("Password verified.\n");
    return NULL;
}

int main() 
{
    pthread_t username_thread, password_thread;
    sem_init(&login_sem, 0, 0);  

    pthread_create(&username_thread, NULL, verify_username, NULL);
    pthread_create(&password_thread, NULL, verify_password, NULL);

    pthread_join(username_thread, NULL);
    pthread_join(password_thread, NULL);

    sem_destroy(&login_sem);
    return 0;
}

