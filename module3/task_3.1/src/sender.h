#ifndef SENDER_H
#define SENDER_H

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>

#define MAX_MSG_SIZE 100
#define MSG_TYPE 1
#define END_MSG_TYPE 255

  struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_SIZE];
  };
void create_file(char *filename);
key_t create_key(char *filename, char id);
int create_message_queue(char *filename, char id);

void send_message(int msgid);
void send_end_message(int msgid);
#endif