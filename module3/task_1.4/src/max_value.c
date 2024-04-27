#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
  float value = atof(argv[1]);
  for (int i = 2; i < argc; i++) {
    float num_argv = atof(argv[i]);
    if (value < num_argv) {
      value = num_argv;
    }
  }
  printf("max value %.2f\n", value);
}