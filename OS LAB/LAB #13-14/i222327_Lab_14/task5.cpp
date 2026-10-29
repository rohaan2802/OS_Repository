#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>


using namespace std;


sem_t read_lock;         
sem_t write_lock;     
int r_count = 0;
int shared_data_var = 0;

void reader(int r_id) 
{
    while (true) 
    {
        sem_wait(&read_lock);
        r_count++;
        if (r_count == 1) 
        {
            sem_wait(&write_lock);  
        }
        sem_post(&read_lock);

        cout << "[Reader " << r_id << "] is reading: " << shared_data_var << "\n";
        sleep(rand() % 2 + 1);  

        sem_wait(&read_lock);
        r_count--;
        
        if (r_count == 0) 
        {
            sem_post(&write_lock); 
        }
        sem_post(&read_lock);

        sleep(rand() % 4 + 1);  
    }
}

void writer(int writerID) 
{
    while (true) 
    {
        sem_wait(&write_lock);  

        shared_data_var += 10;
        std::cout << ">>> [Writer " << writerID << "] wrote data: " << shared_data_var << "\n";
        sleep(rand() % 3 + 1);  

        sem_post(&write_lock);  
        
        sleep(rand() % 5 + 1);  
    }
}

int main() 
{
    srand(time(NULL));
    sem_init(&read_lock, 0, 1);
    sem_init(&write_lock, 0, 1);


    thread readers[5];
    thread writers[2];

    for (int i = 0; i < 5; ++i) 
    {
        readers[i] = thread(reader, i + 1);
    }

    for (int i = 0; i < 2; ++i) 
    {
        writers[i] = thread(writer, i + 1);
    }

    for (int i = 0; i < 5; ++i) 
    {
        readers[i].join();
    }

    for (int i = 0; i < 2; ++i) 
    {
        writers[i].join();
    }

    sem_destroy(&read_lock);
    sem_destroy(&write_lock);
    return 0;
}

