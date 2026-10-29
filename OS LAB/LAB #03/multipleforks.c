#include <stdio.h>
#include <unistd.h>

int main() {
    fork();  // First fork
    fork();  // Second fork

    printf("Process running: PID = %d\n", getpid());
    return 0;
}

