#include "main.h"

int file_locked = 0;

int main() {
  pid_t pid;
  FILE *file = fopen("src/numbers.txt", "r+");
  if (file == NULL) {
    perror("fopen");
    return 1;
  }

  int pipe_fd[2];
  if (pipe(pipe_fd) == -1) {
    perror("pipe");
    return 1;
  }

  signal(SIGUSR1, signal_handler);
  signal(SIGUSR2, signal_handler);

  switch (pid = fork()) {
    case -1:
      perror("fork");
      exit(EXIT_FAILURE);
    case 0:
      child_process(pipe_fd, file);
      exit(EXIT_SUCCESS);
    default:
      parent_process(pipe_fd, file, pid);
      exit(EXIT_SUCCESS);
  }
  return 0;
}
