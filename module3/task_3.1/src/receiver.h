#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100
#define MSG_TYPE 1
#define END_MSG_TYPE 255

struct msgbuf {
  long mtype;
  char mtext[MAX_MSG_SIZE];
};

void received_message(int msgid);
#endif