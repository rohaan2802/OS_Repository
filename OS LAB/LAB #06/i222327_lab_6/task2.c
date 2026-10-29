#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{

     char buffer[100];


    int fd = open("file.txt", O_RDONLY);

    dup2(fd, 0);
    close(fd);
    
    fgets(buffer, sizeof(buffer), stdin);
    
        printf("%s", buffer); 
    

  //  return 0;

}
