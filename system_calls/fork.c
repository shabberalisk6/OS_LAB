#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main() {
    pid_t childPid;

    // Fork the process
    childPid =fork();

    if (childPid == -1) {
        perror("Error creating child process");
        return 1;
    }

    // Check if the current process is the parent or child
    if (childPid == 0) {
        // Code for the child process
        printf("Child process: PID = %d\n", getpid());
    } else {
        // Code for the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), childPid);
    }
    
    return 0;
}
