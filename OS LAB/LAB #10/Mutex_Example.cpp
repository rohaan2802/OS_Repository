//EXAMPLE 1 – Simple Mutex with Two Threads
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex1;
int counter = 0;

void* functionC(void*) {
    pthread_mutex_lock(&mutex1);
    counter++;
    cout << "Thread " << pthread_self() << " Counter value: " << counter << endl;
    pthread_mutex_unlock(&mutex1);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex1, NULL);

    pthread_create(&thread1, NULL, functionC, NULL);
    pthread_create(&thread2, NULL, functionC, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex1);

    return 0;
}
