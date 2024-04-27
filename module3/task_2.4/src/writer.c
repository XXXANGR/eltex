#include "write.h"


int main() {
  int fd_fifo;

  char *my_fifo = "my_fifo";

  unlink("my_fifo");

  if ((mkfifo(my_fifo, 0666)) == -1) {
    fprintf(stderr, "Невозможно создать fifo\n");
    exit(0);
  }

  if ((fd_fifo = open(my_fifo, O_WRONLY)) == -1) {
    fprintf(stderr, "Невозможно открыть fifo\n");
    exit(0);
  }

  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    int random_num = rand() % 100;
    write(fd_fifo, &random_num, sizeof(random_num));
  }
  close(fd_fifo);

  return 0;
}
