#include <iostream>
#include <pthread.h>
#include <unistd.h>  // For sleep()

// Function that will be executed by the thread
void* printMessage(void* arg) {
    std::cout << "Hello from the new thread!" << std::endl;
    return nullptr;
}

int main() {
    pthread_t thread;  // Declare a thread variable

    // Create a new thread and run printMessage function
    pthread_create(&thread, NULL, printMessage, NULL);

    // Wait for the thread to finish before exiting
    sleep(2);

    std::cout << "Main thread finished!" << std::endl;
    return 0;
}
