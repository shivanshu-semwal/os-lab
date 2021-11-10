#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    // A will be printed twice
    printf("A\n");
    fork();
    // B will be printed four times
    printf("B\n");
    fork();
    // C will be printed five times
    printf("C\n");
    return 0;
}
