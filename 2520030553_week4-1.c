#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        sleep(2);
        printf("Child terminating...\n");
        exit(0);
    }
    else {
        printf("Parent PID: %d\n", getpid());

        wait(NULL);

        printf("Child  terminated\n");

    }

    return 0;
}