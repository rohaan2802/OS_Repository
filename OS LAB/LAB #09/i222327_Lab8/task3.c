#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep()

void *book_ticket_1(void *arg)
{
    printf("Thread 1: Booking ticket for Customer 1, Thread ID: %lu\n", pthread_self());
    pthread_exit(NULL);
}

void *book_ticket_2(void *arg)
{
    printf("Thread 2: Booking ticket for Customer 2, exiting...\n");
    pthread_exit(NULL);
}

void *book_ticket_3(void *arg)
{
    printf("Thread 3: Booking ticket for Customer 3, Seat Confirmed!\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2, t3; 
    pthread_create(&t1, NULL, book_ticket_1, NULL);
    pthread_create(&t2, NULL, book_ticket_2, NULL);
    pthread_create(&t3, NULL, book_ticket_3, NULL);


    printf("All ticket bookings completed!\n");

    return 0;
}

