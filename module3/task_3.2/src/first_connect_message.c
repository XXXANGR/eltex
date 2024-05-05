#include "first_user.h"

int connect_message(key_t key) {
  int msgid;
  if ((msgid = msgget(key, IPC_CREAT | 0644)) == -1) {
    perror("msgget");
    exit(EXIT_FAILURE);
  }
  return msgid;
}