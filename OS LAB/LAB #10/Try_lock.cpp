#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t mutex1; // Declare mutex (not initialized yet)

void* threadFunc(void*) {
    if (pthread_mutex_trylock(&mutex1) == 0) {
        // Lock acquired successfully
        cout << "Thread " << pthread_self() << " got the lock!" << endl;
        pthread_mutex_unlock(&mutex1);
    } else {
        // Lock not available
        cout << "Thread " << pthread_self() << " could NOT get the lock!" << endl;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex1, NULL);  // Manual (dynamic) initialization

    

    // Try to lock it from other threads
    pthread_create(&t1, NULL, threadFunc, NULL);
    pthread_create(&t2, NULL, threadFunc, NULL);
    pthread_mutex_lock(&mutex1);        // Lock held by main thread
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_unlock(&mutex1);      // Release lock
    pthread_mutex_destroy(&mutex1);     // Destroy mutex

    return 0;
}
