#include "first_user.h"

void send_message(int msgid, struct msgbuf *msg) {
  if (msgsnd(msgid, msg, sizeof(msg->mtext), 0) == -1) {
    perror("msgsnd");
    exit(EXIT_FAILURE);
  }
}