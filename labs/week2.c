// parent -> sum of even
// child -> sum of odd

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define max 20

int main() {
    pid_t pid;
    int a[max], n, sum = 0, i, status;

    printf("Enter the no of terms in the array: ");
    scanf("%d", &n);

    printf("Enter values in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    pid = fork();
    // wait(&status);

    if (pid == 0) {
        // child process
        for (i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                sum = sum + a[i];
            }
        }
        printf("Sum of odd no. = %d\n", sum);
        exit(0);
    } else {
        // parent process
        for (i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                sum = sum + a[i];
            }
        }
        printf("Sum of even nos = %d\n", sum);
    }
    return 0;
}