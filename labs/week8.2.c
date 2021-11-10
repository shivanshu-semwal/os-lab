// shared memory
// reader

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {
    key_t key;
    int shmid; // shared memory id
    char *ptr; // pointer to shared memory location

    // generate a unique key
    key = ftok("shmfile", 'A');

    // get shared memory segment
    // pass key, size, flag
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // attach shared memory segment
    ptr = shmat(shmid, (void *)0, 0);

    printf("The Data stored : %s\n", ptr);

    // detach shared memory segment
    shmdt(ptr);

    // shared memory control operation
    // remove id
    shmctl(shmid, IPC_RMID, NULL);

    return (0);
}