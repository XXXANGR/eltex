#include "first_user.h"

void delete_message(int msgid) {
  if (msgctl(msgid, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(EXIT_FAILURE);
  }
}