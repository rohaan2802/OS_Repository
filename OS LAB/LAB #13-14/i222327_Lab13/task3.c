#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t pc_sem;
int buffer;

void* producer(void* arg) {
    while (1) {
        buffer = rand() % 100;
        printf("Produced: %d\n", buffer);
        sem_post(&pc_sem);  
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&pc_sem);  
        printf("Consumed: %d\n", buffer);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;
    sem_init(&pc_sem, 0, 0);  

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&pc_sem);
    return 0;
}

