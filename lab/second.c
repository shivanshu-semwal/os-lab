#include <stdio.h>
#include <unistd.h>

int main() {
    // 1 will be printed once
    printf("1\n");
    fork();
    // 2 will be printed twice
    printf("\t2\n");
    fork();
    // 3 will be printed 4 times
    printf("\t\t3\n");
    fork();
    // 4 will be printed 8 times
    printf("\t\t\t4\n");
    return 0;
}
