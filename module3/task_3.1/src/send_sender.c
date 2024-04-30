#include "sender.h"


void send_message(int msgid){
  struct msgbuf msg;
  msg.mtype = MSG_TYPE;

  for (int i = 0; i < 10; i++) {
    sprintf(msg.mtext, "%d", rand() % 100);
    if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
      perror("msgsnd");
      exit(EXIT_FAILURE);
    }
    printf("Sent: %s type %ld\n", msg.mtext, msg.mtype);
  }

}


void send_end_message(int msgid) {
    struct msgbuf msg;
    msg.mtype = END_MSG_TYPE;
    if (msgsnd(msgid, &msg, 0, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
}