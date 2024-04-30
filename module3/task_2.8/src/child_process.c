#include "main.h"

void child_process(int pipe_fd[2], FILE *file) {
  printf("Child pid = %d\n", getpid());
  close(pipe_fd[1]);
  int number;
  if (read(pipe_fd[0], &number, sizeof(number)) > 0) {
    printf("The number has been read: %d\n", number);
    printf("Child process: %d send signal SIGUSR2 after reading \n", getpid());
    kill(getppid(), SIGUSR2);
  }
  close(pipe_fd[0]);
  fclose(file);
  exit(EXIT_SUCCESS);
}