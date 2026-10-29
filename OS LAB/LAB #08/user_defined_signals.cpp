#include <iostream>
#include <signal.h>
using namespace std;

void handleSignal(int signum) {
    cout << "Received Signal: " << signum << endl;
}

int main() {
    signal(SIGINT, handleSignal);
    while (true) {
        cout << "Running... Press Ctrl+C\n";
        sleep(2);
    }
}
