#include "client.h"

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
    if ((msgid = msgget(key, 0666)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    return msgid;
}

void send_msg(int msgid, struct msgbuf *msg) {
    msg->mtype = SERVER_MSG_TYPE;
    msg->pid = getpid();
    if (msgsnd(msgid, msg, sizeof(struct msgbuf) - sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
}

void receive_msg(int msgid, struct msgbuf *msg) {
    if (msgrcv(msgid, msg, sizeof(struct msgbuf) - sizeof(long), getpid(), 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }
}