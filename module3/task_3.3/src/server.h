#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 100
#define SERVER_MSG_TYPE 1
#define ADD_MSG_SIZE 50

struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_SIZE];
    pid_t pid; 
};

int get_msg_queue_id(key_t key);
void receive_msg(int msgid, struct msgbuf *msg);
int add_client(pid_t clients[], int *client_count, pid_t pid);
void send_msg_all_clients(int msgid, pid_t clients[], int client_count, struct msgbuf *msg, char *format_msg);
void create_file(char *filename);
key_t get_key(const char *path, int id);
#endif 