#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char command[100];
    pid_t pid;

    printf("Enter a Linux command: ");
    fgets(command, sizeof(command), stdin);

    pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());

        execl("/bin/sh", "sh", "-c", command, NULL);

        exit(1);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        wait(NULL);

        printf("Child process finished\n");
    }

    return 0;
}
