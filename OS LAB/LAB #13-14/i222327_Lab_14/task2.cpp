#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

sem_t study_room_num;

void studentStudy(int studentID) 
{
    std::cout << "Student " << studentID << " is waiting for a study room...\n";
    sem_wait(&study_room_num);  

    std::cout << "Student " << studentID << " is studying...\n";
    sleep(rand() % 3 + 1);  
    std::cout << "Student " << studentID << " has left the study room.\n";

    sem_post(&study_room_num);  
}

int main() 
{
    srand(time(NULL));
    
    
    sem_init(&study_room_num, 0, 10);

    thread students[20];

    for (int i = 0; i < 20; ++i) 
    {
        students[i] = thread(studentStudy, i + 1);
    }

    for (int i = 0; i < 20; ++i) 
    {
        students[i].join();
    }

    sem_destroy(&study_room_num);
    
    return 0;
}

