//Example: Using sigset_t to Manage Signals
#include <iostream>
#include <signal.h>

using namespace std;

int main() {
    sigset_t myset; // Declare a signal set

    sigemptyset(&myset);  // Start with an empty signal set
    sigaddset(&myset, SIGINT);  // Add SIGINT (Ctrl+C) to the set
    sigaddset(&myset, SIGTERM); // Add SIGTERM to the set

    cout << "SIGINT added to set? " << sigismember(&myset, SIGINT) << endl;
    cout << "SIGTERM added to set? " << sigismember(&myset, SIGTERM) << endl;
    cout << "SIGKILL in set? " << sigismember(&myset, SIGKILL) << endl;

    sigdelset(&myset, SIGINT); // Remove SIGINT
    cout << "After removal, SIGINT in set? " << sigismember(&myset, SIGINT) << endl;

    return 0;
}
