#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() 
{
    char *chat_in = "chat_in";
    char *chat_out = "chat_out";

    mkfifo(chat_in, 0666);
    mkfifo(chat_out, 0666);

    int fd1, fd2;
    char buffer[100], arr1[100];

    while (1)
    {
        fd1 = open(chat_in, O_WRONLY);
       

       fd2 = open(chat_out, O_RDONLY);
        

        printf("You: ");
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  

        write(fd1, buffer, strlen(buffer) + 1);
        close(fd1);

        if (strcmp(buffer, "bye") == 0) 
        {
            break;
        }

      read(fd2, arr1, 100);
        close(fd2);

        if (strcmp(arr1, "bye") == 0) 
        {
            printf("Friend: bye\n");
            break;
        }

        printf("Friend: %s\n", arr1);
    }

  }
  return 0;
}

