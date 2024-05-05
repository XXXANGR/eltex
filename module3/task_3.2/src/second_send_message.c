#include "second_user.h"

void send_message(int msgid) {
  struct msgbuf msg;

  printf("2 user: ");
  fgets(msg.mtext, sizeof(msg.mtext), stdin);

  msg.mtype = MSG_TYPE;
  if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
    perror("msgsnd");
    exit(EXIT_FAILURE);
  }
}