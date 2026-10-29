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

    int fd1, fd2;
    char buffer[100], arr[100];

    while (1) 
    {
        
        fd1 = open(chat_in, O_RDONLY);
     
        fd2 = open(chat_out, O_WRONLY);
      
        
        read(fd1, buffer, 100);
        close(fd1);

        if (strcmp(buffer, "bye") == 0)
        {
            printf("Friend: bye\n");
            break;
        }

        printf("Friend: %s\n", buffer);


        printf("You: ");
        fgets(arr, 100, stdin);
        arr[strcspn(arr, "\n")] = 0; 
        
        
       write(fd2, arr, strlen(arr) + 1);
        close(fd2);

        if (strcmp(arr, "bye") == 0) 
        {
            break;
        }
    }

    printf("Chat ended.\n");
}
return 0;
}

