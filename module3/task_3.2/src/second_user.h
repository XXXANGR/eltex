#ifndef SECOND_USER_H
#define SECOND_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100
#define MSG_TYPE 1

struct msgbuf {
  long mtype;
  char mtext[MAX_MSG_SIZE];
};

int connect_message(key_t key);
key_t get_key();
void receive_message(int msgid);
void send_message(int msgid);
#endif