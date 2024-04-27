#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float sum;
  float num;

  for (int i = 0; i < argc; i++) {
    num = atof(argv[i]);
    sum += num;
  }

  printf("%.2f\n", sum);
  return 0;
}