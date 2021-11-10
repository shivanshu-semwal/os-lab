#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#define MAX 200

int main() {

    int PID;

    int a[MAX], n, sum = 0, status;

    scanf("%d", &n); // size of the array

    // input the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    PID = fork();
    wait(&status);
    if (PID == 0) { // child process
        /* sum = 0; */
        for (int j = 0; j < n; j++) {
            if (a[j] % 2 == 0) {
                sum += a[j];
                printf("child\n");
            }
        }
        printf("Sum of even no = %d\n", sum);
    } else { // child process
        for (int j = 0; j < n; j++) {
            if (a[j] % 2 != 0) {
                sum += a[j];
                printf("parent\n");
            }
        }
        printf("Sum of odd no = %d", sum);
    }
    return 0;
}
