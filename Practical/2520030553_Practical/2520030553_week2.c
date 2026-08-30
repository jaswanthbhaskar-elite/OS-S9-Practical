#include <fcntl.h>   // for open()
#include <unistd.h>  // for read(), write(), close()
#include <stdio.h>   // for perror()
#include <stdlib.h>  // for exit()

int main(int argc, char *argv[]) {
    int src, dst;
    char buf[1024];
    ssize_t n;

    if (argc != 3) {
        write(2, "Usage: copy <source> <dest>\n", 28);
        exit(1);
    }

    src = open(argv[1], O_RDONLY);
    if (src < 0) { perror("open source"); exit(1); }

    dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) { perror("open dest"); close(src); exit(1); }

    while ((n = read(src, buf, sizeof(buf))) > 0) {
        if (write(dst, buf, n) != n) { perror("write"); exit(1); }
    }
    if (n < 0) perror("read");

    close(src);
    close(dst);
    return 0;
}
