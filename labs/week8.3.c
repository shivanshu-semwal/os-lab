// shared memory
// both reader and writer

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SIZE 100

int main() {
    key_t key;
    int shmid; // shared memory id
    void *ptr; // pointer to the shared memory location

    // generate a unique key
    key = ftok("srfile", 'A');

    // get shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // attach shared memory segment
    ptr = shmat(shmid, (void *)0, 0);

    printf("\nInput Data:");
    fgets(ptr, SIZE, stdin);

    printf("The Data stored : %s\n", (char *)ptr);

    // detach the shared memory segment
    shmdt(ptr);

    // remove id of the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    
    return (0);
}