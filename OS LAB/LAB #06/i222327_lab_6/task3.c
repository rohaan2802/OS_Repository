#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    
    dup2(fd, 2);
    close(fd); 
    
    fprintf(stderr, "Error: Something went wrong!\n");
    return 0;
}

