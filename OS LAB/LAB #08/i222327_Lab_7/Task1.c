#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

void handle_signal_int(int var)
{
    printf("\n\n\t\t\t\tSIGINT (CTRL+C) RECEIVED! IGNORING CTRL+C.\n");
}

void handle_signal_term(int var)
{
    printf("\n\n\t\t\t\tSIGTERM RECEIVED! EXITING PROGRAM.\n");
    exit(0);
}

void handle_signal_alarm(int var)
{
    printf("\n\n\t\t\t\tSIGALRM RECEIVED! TIMER EXPIRED.\n");
}

void main()
{
    printf("\t\t\t\t%d",getpid());
    signal(SIGINT, handle_signal_int);
    signal(SIGTERM, handle_signal_term);
    signal(SIGALRM, handle_signal_alarm);
    
    alarm(13);
    
    while (1) 
    {
        pause();      
    }

}
