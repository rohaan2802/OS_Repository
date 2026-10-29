#include <iostream>
#include <pthread.h>
#include <unistd.h>

// Function to display thread ID
void* showThreadID(void* arg) {
    pthread_t threadID = pthread_self();  // Get thread ID
    std::cout << "Thread ID: " << threadID << std::endl;
    return nullptr;
}

int main() {
    pthread_t thread;

    // Create a new thread
    pthread_create(&thread, NULL, showThreadID, NULL);

    // Wait for the thread to finish
    sleep(2);
    std::cout << "Main thread exiting!" << std::endl;
    return 0;
}
