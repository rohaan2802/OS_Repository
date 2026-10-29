//temporarily blocks signals and pauses the program until it receives a signal that is not blocked.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void signal_handler(int signo) {
    printf("\nReceived signal %d. Resuming program...\n", signo);
}

int main() {
    sigset_t mask, old_mask;

    printf("Program started (PID: %d)\n", getpid());

    // Set up signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signal_handler);

    // Block SIGINT
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigprocmask(SIG_BLOCK, &mask, &old_mask);
    printf("SIGINT is blocked. Try pressing Ctrl+C, nothing happens!\n");

    printf("Waiting for a signal...\n");

    // Wait until a signal is received
    sigsuspend(&old_mask);

    printf("Resuming normal execution...\n");

    return 0;
}
