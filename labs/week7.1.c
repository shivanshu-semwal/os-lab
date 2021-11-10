// message queue
// writer

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define SIZE 100

struct msgbuf {
    long mtype;
    char mtext[SIZE];
}svarname;

int main() {
    key_t key;
    int msgid, c;
    
    // create a key
    key = ftok("progfile", 'A');

    // get a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    //
    svarname.mtype = 1;

    printf("Enter a string : ");
    fgets(svarname.mtext, SIZE, stdin);

    // sending msg to message queue
    // msgid, msgp, msg_size, flags
    c = msgsnd(msgid, &svarname, strlen(svarname.mtext), 0);

    printf("Sender wrote the text :\t %s \n", svarname.mtext);

    return 0;
}