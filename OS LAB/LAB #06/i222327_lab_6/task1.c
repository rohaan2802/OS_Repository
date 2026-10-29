#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{

    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    int fd_dup = dup(fd);
    
    dup2(fd_dup, 1);
    
    close(fd);

    printf("Hello world\n");

  //  return 0;

}
