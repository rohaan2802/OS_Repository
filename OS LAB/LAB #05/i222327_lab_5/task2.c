#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
printf("\n\nHELLOO WORLD.......\n\n");

int arr1[2],arr2[2];
pipe(arr1);
pipe(arr2);

int process_id=fork();
char msgz[3][50]= {"Message 1", "Message 2", "Message 3"};
char buffer[50];

if(process_id>1)
{
close(arr1[0]);//parent_read_close
close(arr2[1]);//child_write_close

	 for (int i = 0; i < 3; i++)
 	 {
            write(arr1[1], msgz[i], sizeof(msgz[i]));//paret_write
            read(arr2[0], buffer, 50);//child_read
            printf("\n\nPARENT RECEIVED : %s\n\n", buffer);
        	}

        close(arr1[1]); // parent_write_close
        close(arr2[0]); // child_read_close
}
else
{
 close(arr1[1]); // parent_write_close
 close(arr2[0]); // child_read_close
 
 	for (int i = 0; i < 3; i++) 
 	{
            read(arr1[0], buffer, 50);
            printf("\n\nCHILD RECEIVED: %s\n\n", buffer);
            printf("\n\nACKNOWLOEDGE %s\n\n", buffer);
            write(arr2[1], buffer, 50);
        }

        close(arr1[0]); // parent_read_close
        close(arr2[1]); // child_write_close
        
}


}


