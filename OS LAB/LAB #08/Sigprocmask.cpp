//Blocking & Restoring Signals

#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

int main() {
    sigset_t new_mask, old_mask;

    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGINT); // Block SIGINT (Ctrl+C)

    // Apply new mask: Block SIGINT
    sigprocmask(SIG_BLOCK, &new_mask, &old_mask);
    cout << "SIGINT is now blocked. Try pressing Ctrl+C (It won’t work!)\n";
    
    sleep(10); // Wait for 10 seconds

    // Restore previous mask: Unblock SIGINT
    sigprocmask(SIG_SETMASK, &old_mask, NULL);
    cout << "SIGINT is now unblocked. You can use Ctrl+C again.\n";

    while (true) {
        sleep(1);
    }

    return 0;
}
