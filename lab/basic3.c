#include <stdio.h>
#include <unistd.h>

int main() {

    // A will be printed once
    printf("A\n");
    fork();
    // C will be printed twice
    printf("C\n");
    fork();
    // B will be printed 4 times
    printf("B\n");
    return 0;
}
