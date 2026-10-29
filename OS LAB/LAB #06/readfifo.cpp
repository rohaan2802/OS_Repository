#include <fcntl.h>   // For open()
#include <iostream>
#include <unistd.h>  // For read() and close()
#include <cstring>   // For string operations
using namespace std;
int main() {
    char message[256];  // Buffer for receiving messages

    // Open the named pipe for reading
    int fifo_read = open("pipe_one", O_RDONLY);
    
    if (fifo_read < 0) {
        cout << "Error opening FIFO for reading!" << endl;
        return 1;
    }

    while (true) {
        // Read message from FIFO
        read(fifo_read, message, sizeof(message));

        cout << "Received: " << message << endl;

        if (strcmp(message, "exit") == 0) break;  // Exit condition
    }

    close(fifo_read); // Close the FIFO
    return 0;
}

