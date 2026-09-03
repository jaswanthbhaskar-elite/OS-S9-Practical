#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char message[100];

    int fd = open("myfifo", O_WRONLY);

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    write(fd, message, sizeof(message));

    close(fd);

    return 0;
}