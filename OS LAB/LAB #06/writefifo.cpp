#include <fcntl.h>   // For open()
#include <iostream>
#include <unistd.h>  // For write() and close()
#include <cstring>   // For string operations
using namespace std;

int main() {
    char message[256];  // Buffer for message input

    // Open the named pipe for writing
    int fifo_write = open("pipe_one", O_WRONLY);
    
    if (fifo_write < 0) {
        cout << "Error opening FIFO for writing!" << endl;
        return 1;
    }

    while (true) {
        cout << "Enter message (type 'exit' to quit): ";
        cin.getline(message, 256);  // Read user input

        // Write the message to FIFO
        write(fifo_write, message, strlen(message) + 1);

        if (strcmp(message, "exit") == 0) break;  // Exit condition
    }

    close(fifo_write); // Close the FIFO
    return 0;
}

