#include "main.h"


int main(int argc, char *argv[]) {
  pid_t pid;
  int rv;
  float length;
  float area;

  switch (pid = fork()) {
  case -1:
    perror("fork");
    exit(EXIT_FAILURE);
  case 0:
    printf("child: PID - %d\n", getpid());
    for (int i = argc / 2; i < argc; i++) {
      length = atof(argv[i]);
      area = square_area(length);
      printf("child: Square area for argv[%d] - %f\n", i, area);
    }
    exit(EXIT_SUCCESS);
  default:
    printf("Parent: PID - %d\n", getpid());
    for (int i = 1; i < argc / 2; i++) {
      length = atof(argv[i]);
      area = square_area(length);
      printf("Parent: Square area for argv[%d] - %f\n", i, area);
    }
    wait(&rv);
    printf("Parent: RETURN STATUS FOR child - %d\n", WEXITSTATUS(rv));
  }
  exit(EXIT_SUCCESS);
}
