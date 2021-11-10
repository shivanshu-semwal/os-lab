//SINGLE FORK

//HEADER FILES
#include <stdio.h>
#include <unistd.h>

int main() {
    //CALLING FORK TO CREATE A CHILD PROCESS
    fork();
    printf("LINUX\n");
    return 0;
}