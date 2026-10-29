//Checks if a blocked signal is waiting to be handled.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t new_mask, pending;

    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGINT); // Block SIGINT (Ctrl+C)
    sigprocmask(SIG_BLOCK, &new_mask, NULL); // Apply block

    printf("SIGINT is now blocked. Try pressing Ctrl+C.\n");

    sleep(5); // Give time to press Ctrl+C

    // Check pending signals
    sigpending(&pending);
    if (sigismember(&pending, SIGINT)) {
        printf("SIGINT was received but is pending due to blocking.\n");
    }

    // Unblock SIGINT
    sigprocmask(SIG_UNBLOCK, &new_mask, NULL);
    printf("SIGINT is now unblocked. Press Ctrl+C again to exit.\n");

    while (1) sleep(1);

    return 0;
}
