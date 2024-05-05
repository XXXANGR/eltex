#include "first_user.h"

void create_file() {
  int fd = open("msg_queue", O_CREAT, 0644);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }
  close(fd);
}