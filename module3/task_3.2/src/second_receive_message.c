#include "second_user.h"

void receive_message(int msgid) {
  struct msgbuf msg;

  if (msgrcv(msgid, &msg, sizeof(msg.mtext), MSG_TYPE, 0) == -1) {
    perror("msgrcv");
    exit(EXIT_FAILURE);
  }
  printf("1 user: %s", msg.mtext);
}