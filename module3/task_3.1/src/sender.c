#include "sender.h"

int main() {
  char id = 'A';
  char *filename = "msg_queue";
  create_file(filename);

  int msgid = create_message_queue(filename, id);
  send_message(msgid);

  send_end_message(msgid);

  return 0;
}
