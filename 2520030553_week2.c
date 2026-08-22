#include <fcntl.h>
#include <unistd.h>

int main() {
    int source, destination;
    char buffer[100];
    int n;

    source = open("source.txt", O_RDONLY);
    destination = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((n = read(source, buffer, 100)) > 0) {
        write(destination, buffer, n);
    }

    close(source);
    close(destination);

    return 0;
}
