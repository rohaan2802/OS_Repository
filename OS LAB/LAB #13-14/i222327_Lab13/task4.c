#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


int arr[20];
int global_max = -1;
sem_t max_sem;

void* find_max(void* arg) 
{
    int index = (int)(size_t)arg;
    int start = index * (20 / 4);
    int end = start + (20 / 4);
    int local_max = arr[start];

    for (int i = start; i < end; ++i) {
        if (arr[i] > local_max)
            local_max = arr[i];
    }

    sem_wait(&max_sem);
    if (local_max > global_max)
        global_max = local_max;
    sem_post(&max_sem);

    return NULL;
}

int main() {
    pthread_t threads[4];
    sem_init(&max_sem, 0, 1);


    printf("Array: ");
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");


    for (int i = 0; i < 4; ++i) {
        pthread_create(&threads[i], NULL, find_max, (void*)(size_t)i);
    }

    for (int i = 0; i < 4; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Maximum value in array: %d\n", global_max);
    sem_destroy(&max_sem);
    return 0;
}

