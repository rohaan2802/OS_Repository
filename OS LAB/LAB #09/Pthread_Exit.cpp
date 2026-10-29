#include <iostream>
#include <pthread.h>
#include <unistd.h>

// Function that exits the thread
void* worker(void* arg) {
    std::cout << "Worker thread started!" << std::endl;
    sleep(2);
    std::cout << "Worker thread exiting..." << std::endl;
    pthread_exit(NULL);  // Exit the thread
}

int main() {
    pthread_t thread;

    // Create a new thread
    pthread_create(&thread, NULL, worker, NULL);

    sleep(5);

    std::cout << "Main thread exiting!" << std::endl;
    return 0;
}
