#include <fcntl.h>   // For open()
#include <iostream>
#include <unistd.h>  // For read() and close()
#include <cstring>   // For string operations
using namespace std;

int main() {
    char message[256];  // Buffer for receiving messages

    // Open the named pipe for reading in non-blocking mode
    int fifo_read = open("pipe_one", O_RDONLY | O_NONBLOCK);
    
    if (fifo_read < 0) {
        cout << "Error opening FIFO for reading!" << endl;
        return 1;
    }

    while (true) {
        // Read message from FIFO
        int bytes_read = read(fifo_read, message, sizeof(message));

        if (bytes_read > 0) {
            cout << "Received: " << message << endl;
            if (strcmp(message, "exit") == 0) break;  // Exit condition
        } else {
            cout << "No data available..." << endl;
        }

        sleep(1); // Prevents excessive CPU usage
    }

    close(fifo_read); // Close the FIFO
    return 0;
}

