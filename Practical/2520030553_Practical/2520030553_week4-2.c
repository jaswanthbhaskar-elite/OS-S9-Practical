#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    if (fork() == 0) {

        printf("Child process running...\n");
        printf("Child PID: %d\n", getpid());

        exit(0);
    }

    else {

        printf("Parent PID: %d\n", getpid());

        sleep(20);

        printf("Parent finished.\n");
    }

    return 0;
}