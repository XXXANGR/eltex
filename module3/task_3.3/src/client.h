#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_SIZE 100
#define SERVER_MSG_TYPE 1

struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_SIZE];
    pid_t pid;
};
key_t get_key(const char *path, int id);
int get_msg_queue_id(key_t key);
void send_msg(int msgid, struct msgbuf *msg);
void receive_msg(int msgid, struct msgbuf *msg);

#endif