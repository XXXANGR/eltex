#ifndef FIRST_USER_H
#define FIRST_USER_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_MSG_SIZE 100
#define MSG_TYPE 1
#define END_MSG_TYPE 255

struct msgbuf {
  long mtype;
  char mtext[MAX_MSG_SIZE];
};

key_t get_key();
int connect_message(key_t key);
void create_file();
void receive_message(int msgid, struct msgbuf *msg);
void send_message(int msgid, struct msgbuf *msg);
void delete_message(int msgid);

#endif