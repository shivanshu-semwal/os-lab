// message queue
// reader

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define SIZE 100

struct msgbuf {
    long mtype;
    char mtext[SIZE];
} svarname;

int main() {
    key_t key;
    int msgid, c;

    // create a key
    key = ftok("progfile", 'A');

    // get a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // receive a message from message queue
    // msgid, msgp, msg_size, msg_type, flags
    msgrcv(msgid, &svarname, sizeof(svarname), 1, 0);

    printf("Data Received is %s\n", svarname.mtext);

    // message queue control operation
    msgctl(msgid, IPC_RMID, NULL);
    
    return 0;
}