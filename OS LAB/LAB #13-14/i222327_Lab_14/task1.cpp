#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>  
#include <cstdlib>   
#include <ctime>    
using namespace std; 





sem_t cookingStations;

void cookOrder(int orderID) 
{
    cout << "Order " << orderID << " is waiting for a cooking station...\n";
    sem_wait(&cookingStations);  

    cout << "Order " << orderID << " is being cooked.\n";
    sleep(rand() % 3 + 1); 
    cout << "Order " << orderID << " is done!\n";

    sem_post(&cookingStations);  
}

int main() 
{
    srand(time(NULL));
    sem_init(&cookingStations, 0, 4);

    thread threads[10];  

    for (int i = 0; i < 10; ++i) 
    {
        threads[i] = thread(cookOrder, i + 1);
    }

    for (int i = 0; i < 10; ++i) 
    {
        threads[i].join();
    }

    sem_destroy(&cookingStations);
    
    return 0;
}

