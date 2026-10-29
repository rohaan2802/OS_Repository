#include <unistd.h>  // For unlink()
#include <iostream>
using namespace std;

int main() {
    // Remove the named pipes
    if (unlink("pipe_one") == 0)
        cout << "pipe_one removed successfully!" << endl;
    else
        cout << "Error: Could not remove pipe_one!" << endl;

    if (unlink("pipe_two") == 0)
        cout << "pipe_two removed successfully!" << endl;
    else
        cout << "Error: Could not remove pipe_two!" << endl;

    return 0;
}

