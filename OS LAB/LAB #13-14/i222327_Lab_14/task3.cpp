#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

sem_t tickets_num;

void bookTicket(int customer_id) 
{
    std::cout << "Customer " << customer_id << " is trying to book a ticket...\n";

    if (sem_trywait(&tickets_num) == 0) 
    {  
        cout << "Customer " << customer_id << " successfully booked a ticket.\n";
        sleep(rand() % 2 + 1);  
    } 
    else 
    {
        cout << "Customer " << customer_id << " could not book a ticket (sold out).\n";
    }
}

int main() 
{
    srand(time(NULL));
    sem_init(&tickets_num, 0, 50);

    thread customers[60];

    for (int i = 0; i < 60; ++i) 
    {
        customers[i] = thread(bookTicket, i + 1);
    }

    for (int i = 0; i < 60; ++i) 
    {
        customers[i].join();
    }

    sem_destroy(&tickets_num);
    return 0;
}

