#include "sender.h"

void create_file(char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  fclose(file);
}

key_t create_key(char *filename, char id) {
  key_t key = ftok("msg_queue", id);
  if (key == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }
  return key;
}

int create_message_queue(char *filename, char id) {
  key_t key = create_key(filename, id);
  int msgid = msgget(key, IPC_CREAT | 0666);
  if (msgid == -1) {
    perror("msgget");
    exit(EXIT_FAILURE);
  }
  return msgid;
}