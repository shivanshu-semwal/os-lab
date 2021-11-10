//MULTI TIME FORK

//HEADER FILES
#include <stdio.h>
#include <unistd.h>

int main() {
    //CALLING FORK TO CREATE A CHILD PROCESS
    fork();
    printf("LINUX\n");
    //CALLING FORK TO CREATE A CHILD PROCESS
    fork();
    printf("UNIX\n");
    //CALLING FORK TO CREATE A CHILD PROCESS
    fork();
    printf("RED HAT\n");
    return 0;
}