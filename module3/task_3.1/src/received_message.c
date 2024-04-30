#include "receiver.h"


void received_message(int msgid){
  struct msgbuf msg;
  while (1) {
    if (msgrcv(msgid, &msg, MAX_MSG_SIZE, 0, 0) == -1) {
      perror("msgrcv");
      exit(EXIT_FAILURE);
    }

    if (msg.mtype == MSG_TYPE) {
      printf("Received: %s type %ld\n", msg.mtext, msg.mtype);
    } else if (msg.mtype == END_MSG_TYPE) {
      printf("Received type 255. Exit\n");
      break;
    }
  }
}