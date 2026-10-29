Example 1 Explanation:
This program creates a child process using fork(), then the parent process waits for the child process.
The child process kills itself using kill(getpid(), SIGKILL).


pid_t pid; 
pid = fork();  // Create child process

if (pid < 0) {  
    cout << "Child process not created" << endl;
} 
else if (pid > 0) {  
    cout << "I am parent with pid " << getpid() << " and child pid is " << pid << endl;
    wait(NULL);  // Parent waits for the child to terminate
} 
else {  
    cout << "I am child with pid " << getpid() << " and my parent pid is " << getppid() << endl;
    kill(getpid(), SIGKILL);  // Child process terminates itself
    cout << "My parent is now " << getppid() << endl;  // This line will not execute since the child is killed
}
