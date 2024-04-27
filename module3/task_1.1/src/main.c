#include "main.h"

int main(int argc, char *argv[]) {
  pid_t pid;
  int rv;

  switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0:
        printf("CHILD: PID - %d\n", getpid());
        printf("CHILD: PPID - %d\n", getppid());
        print_value_arg(argc,argv);
        exit(EXIT_SUCCESS);

    default:
        printf("PARENT: PID - %d\n", getpid());
        printf("PARENT: CHILD PID - %d\n", pid);
        print_value_arg(argc,argv);
        wait(&rv);
        printf("PARENT: RETURN STATUS FOR CHILD - %d\n", WEXITSTATUS(rv));
  }
  exit(EXIT_SUCCESS);
}