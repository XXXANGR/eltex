#include "receiver.h"

int main() {
  key_t key;
  int msgid;
  struct msgbuf msg;

  if ((key = ftok("msg_queue", 'A')) == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }

  if ((msgid = msgget(key, 0644)) == -1) {
    perror("msgget");
    exit(EXIT_FAILURE);
  }
  received_message(msgid);

  return 0;
}
