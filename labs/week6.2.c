// fifo
// reader

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 100

int main() {
    int fd;
    int nbr; // no of bytes read
    char arr[SIZE];

    // make fifo -> myfifo
    mknod("myfifo", S_IFIFO | 0666, 0);

    // open a fifo for read
    // O_RDONLY -> read only permission
    fd = open("myfifo", O_RDONLY);
    
    printf("If you got a writer process then type some data\n");

    do {
        nbr = read(fd, arr, sizeof(arr));
        arr[nbr] = '\0';
        printf("Reader process read %d bytes: %s\n", nbr, arr);
    } while (nbr > 0);

    return 0;
}