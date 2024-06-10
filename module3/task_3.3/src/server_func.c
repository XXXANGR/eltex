#include "server.h"

key_t get_key(const char *path, int id) {
    key_t key;
    if ((key = ftok(path, id)) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    return key;
}

int get_msg_queue_id(key_t key) {
    int msgid;
    if ((msgid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    return msgid;
}

void receive_msg(int msgid, struct msgbuf *msg) {
    if (msgrcv(msgid, msg, sizeof(struct msgbuf) - sizeof(long), SERVER_MSG_TYPE, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }
}

int add_client(pid_t clients[], int *client_count, pid_t pid) {
    for (int i = 0; i < *client_count; ++i) {
        if (clients[i] == pid) {
            return 0; 
        }
    }
    if (*client_count < MAX_CLIENTS) {
        clients[(*client_count)++] = pid;
        return 1; 
    } else {
        printf("Max clients.\n");
        return 0;
    }
}

void send_msg_all_clients(int msgid, pid_t clients[], int client_count, struct msgbuf *msg, char *format_msg) {
    for (int i = 0; i < client_count; ++i) {
        if (clients[i] != msg->pid) { 
            msg->mtype = clients[i];
            strncpy(msg->mtext, format_msg, MAX_MSG_SIZE);
            if (msgsnd(msgid, msg, sizeof(struct msgbuf) - sizeof(long), 0) == -1) {
                perror("msgsnd");
            }
        }
    }
}

void create_file(char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  fclose(file);
}