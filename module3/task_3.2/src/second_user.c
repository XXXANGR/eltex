#include "second_user.h"

int main() {
  key_t key = get_key();
  int msgid = connect_message(key);

  while (1) {
    receive_message(msgid);
    send_message(msgid);
  }

  return 0;
}