#include "main.h"

void main(int argc, char *argv[]) {
  pid_t pid;
  int rv;
  int pipefd[2];
  pipe(pipefd);

  if (argc != 2) {
    printf("Enter: 2 arg\n");
    return;
  }

  int num_numbers = atoi(argv[1]);
  if (num_numbers <= 0) {
    printf("Enter integer number: \n");
    return;
  }

  FILE *file = fopen("numbers.txt", "w");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  switch (pid = fork()) {
    case -1:
      perror("fork");
      exit(EXIT_FAILURE);
    case 0:
      close(pipefd[0]);
      srand(time(NULL));
      for (int i = 0; i < num_numbers; ++i) {
        int number = rand() % 1000;
        write(pipefd[1], &number, sizeof(number));
      }
      exit(EXIT_SUCCESS);
    default:
      close(pipefd[1]);
      wait(&rv);
      int number;
      while (read(pipefd[0], &number, sizeof(number)) > 0) {
        printf("%d\n", number);
        fprintf(file, "%d\n", number);
      }
      fclose(file);
  }
}
