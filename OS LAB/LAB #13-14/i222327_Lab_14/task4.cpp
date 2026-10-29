#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

sem_t traffic_semaphore;

void roadA() 
{
    while (true) 
    {
        sem_wait(&traffic_semaphore);  
        cout << "[Road A] GREEN light. Cars are passing...\n";
        sleep(3); 
        cout << "[Road A] RED light. Stopping cars...\n";
        sem_post(&traffic_semaphore);  
        sleep(1);  
    }
}

void roadB() 
{
    while (true) 
    {
        sem_wait(&traffic_semaphore);
        cout << "[Road B] GREEN light. Cars are passing...\n";
        sleep(3);  
        cout << "[Road B] RED light. Stopping cars...\n";
        sem_post(&traffic_semaphore);
        sleep(1); 
    }
}

int main() 
{
    sem_init(&traffic_semaphore, 0, 1);  

    thread t1(roadA);
    thread t2(roadB);

    t1.join();
    t2.join();

    sem_destroy(&traffic_semaphore);
    return 0;
}

