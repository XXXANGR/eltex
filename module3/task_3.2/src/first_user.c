#include "first_user.h"

int main() {
  create_file();

  key_t key = get_key();
  int msgid = connect_message(key);
  struct msgbuf msg;
  // printf("Начало чата для завершения.\n");

  while (1) {
    printf("1 user: ");
    fgets(msg.mtext, sizeof(msg.mtext), stdin);

    msg.mtype = MSG_TYPE;
    send_message(msgid, &msg);

    receive_message(msgid, &msg);
    printf("2 user: %s", msg.mtext);
  }

  delete_message(msgid);

  return 0;
}