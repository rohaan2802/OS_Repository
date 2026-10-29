#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;

int main() {
    // Create a FIFO (Named Pipe) with read and write permissions (0666)
    int f1 = mkfifo("pipe_one", 0666);
    
    // Check if FIFO was successfully created
    if (f1 < 0) cout << "Error: Pipe one not created" << endl;
    else cout << "Pipe one created successfully" << endl;

    int f2 = mkfifo("pipe_two", 0666);
    if (f2 < 0) cout << "Error: Pipe two not created" << endl;
    else cout << "Pipe two created successfully" << endl;

    return 0;
}

