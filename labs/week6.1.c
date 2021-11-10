// fifo
// writer

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 100

int main() {
    int fd;
    int nbw; // no of bytes written
    char str[SIZE];

    // make fifo -> myfifo
    mknod("myfifo", S_IFIFO | 0666, 0);

    printf("Writing for reader Process:\n");

    // open the fifo for write operation
    // O_WRONLY -> write only operation
    fd = open("myfifo", O_WRONLY);

    while (fgets(str, SIZE, stdin)) {
        nbw = write(fd, str, strlen(str));
        printf("Writer process write %d bytes: %s\n", nbw, str);
    }
    return 0;
}