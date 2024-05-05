#include "first_user.h"

key_t get_key() {
  key_t key;
  if ((key = ftok("msg_queue", 'A')) == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }
  return key;
}