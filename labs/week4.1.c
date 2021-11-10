// orphan process
// process inherited by the init

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        // child
        sleep(6); // wait and let the parent die
        printf("I'm Child. My PID = %d And PPID = %d\n", getpid(), getppid());
    } else {
        // parent
        printf("I'm Parent. My Child PID = %d And my PID = %d\n", pid, getpid());
    }
    printf("Terminating PID = %d\n", getpid());
    return 0;
}