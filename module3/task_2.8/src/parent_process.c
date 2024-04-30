#include "main.h"

void parent_process(int pipe_fd[2], FILE *file, pid_t pid) {
  printf("Parent pid = %d\n", getpid());
  close(pipe_fd[0]);
  int number;
  while (fscanf(file, "%d", &number) != EOF) {
    printf("The number from the file has been read: %d\n", number);
    write(pipe_fd[1], &number, sizeof(number));
    kill(pid, SIGUSR1);
    waitpid(pid, NULL, 0);
    while (file_locked) {
    }
    fseek(file, 0, SEEK_SET);
    fprintf(file, "%d\n", number * 2);
    printf("A new value has been written to the file %d\n", number * 2);
  }
  fclose(file);
  close(pipe_fd[1]);
}