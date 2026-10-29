// Filename: wait_example.c
// This program demonstrates how a parent process waits for its child process.

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        wait(NULL);  // Parent waits for the child to complete
        printf("Child process finished. Now parent resumes.\n");
    } else if (pid == 0) {
        printf("Child process is running...\n");
    } else {
        printf("Fork failed!\n");
    }
    return 0;
}

/*
To compile and execute:
    gcc -o wait_example wait_example.c
    ./wait_example
*/

