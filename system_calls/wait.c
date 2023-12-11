#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t childPid;

    // Create a child process
    childPid = fork();

    if (childPid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (childPid == 0) {
        // Code for child process
        printf("Child process running...\n");
        sleep(2);  // Simulating some work in the child process
        printf("Child process completed.\n");
        exit(EXIT_SUCCESS);
    } else {
        // Code for parent process
        printf("Parent process waiting for the child to finish...\n");

        int status;
        pid_t terminatedChild = wait(&status);

        if (terminatedChild == -1) {
            perror("Wait failed");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child process with PID %d exited with status %d\n", terminatedChild, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process with PID %d terminated by signal %d\n", terminatedChild, WTERMSIG(status));
        }
    }

    return 0;
}
