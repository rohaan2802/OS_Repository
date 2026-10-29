This program demonstrates sending a signal to a parent process from a child process.


#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void handler(int signum) {  
    cout << "Signal is received " << signum << endl;
    sleep(5);
    wait(NULL);  // Parent waits for child termination
}

int main() {  
    int cpid, ppid;
    signal(SIGUSR1, handler);  // Assign handler function to SIGUSR1
    signal(SIGCHLD, handler);  // Assign handler function to SIGCHLD

    cpid = fork();  // Create child process

    switch (cpid) {  
        case -1:  
            cout << "Error" << endl;  
            break;  
        case 0:  
            ppid = getppid();  
            kill(ppid, SIGUSR1);  // Child sends SIGUSR1 signal to parent
            exit(0);
            break;
        default:
            while (kill(cpid, 0) == 0)  
                cout << "waiting for child " << endl;
            cout << "Child terminated. Now I am terminating" << endl;
    }
    
    return 0;
}
