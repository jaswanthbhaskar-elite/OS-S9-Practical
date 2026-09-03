#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int pipefd[2];
    char message[] = "Hello from Producer";
    char buffer[50];

    pipe(pipefd);

    clock_t start = clock();

    if (fork() == 0) {
        // Child - Consumer
        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));
        printf("Consumer received: %s\n", buffer);

        close(pipefd[0]);
    }
    else {
        // Parent - Producer
        close(pipefd[0]);

        write(pipefd[1], message, strlen(message) + 1);
        printf("Producer sent: %s\n", message);

        close(pipefd[1]);
        wait(NULL);

        clock_t end = clock();
        printf("Communication time: %f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);
    }

    return 0;
}