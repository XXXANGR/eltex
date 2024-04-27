#include "main.h"

int main() {
  char stroka[MAX_LENGHT_STRING];
  char *arg[MAX_ARGUMENT] = {0};
  int count = 0;
  char *sep;
  pid_t pid;
  int rv;

  while (1) {
    printf(">>: \n");
    fgets(stroka, sizeof(stroka), stdin);
    stroka[strlen(stroka + 1)] = '\0';

    sep = strtok(stroka, " ");

    while (sep != NULL) {
      arg[count++] = sep;
      sep = strtok(NULL, " ");
    }

    switch (pid = fork()) {
      case -1:
        perror("fork");
        exit(EXIT_FAILURE);
      case 0:
        printf("child: PID - %d\n", getpid());
        if (detect_file(arg[0])) {
          execv(arg[0], arg);
        } else {
          execvp(arg[0], arg);
        }
        perror("the file was not found");
        exit(EXIT_FAILURE);
      default:
        printf("Parent: PID - %d\n", getpid());
        wait(&rv);
        printf("Parent: RETURN STATUS FOR child - %d\n", WEXITSTATUS(rv));
    }
    count = 0;
    memset(arg, 0, sizeof(arg));
  }
  return 0;
}