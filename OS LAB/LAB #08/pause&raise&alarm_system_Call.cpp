
#include <unistd.h>
int main() {
    cout << "Waiting for signal...\n";
    pause();  // Process will stop here until it gets a signal
}

//How to resume it? Send a signal using:

//kill -SIGINT PID
//(The process will wake up when Ctrl + C is pressed.)


//The raise() function sends a signal to itself.

#include <signal.h>
int main() {
    raise(SIGKILL);  // Process will kill itself
}


// alarm()
#include <unistd.h>
int main() {
    alarm(5);  // Sends SIGALRM after 5 seconds
    while (1);
}

// After 5 seconds, the program will automatically exit because SIGALRM is received.
