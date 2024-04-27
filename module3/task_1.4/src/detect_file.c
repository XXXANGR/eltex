#include "main.h"

int detect_file(char *filename) {
  DIR *directory = opendir(".");
  if (directory == NULL) {
    perror("Error opening directory \n");
    exit(EXIT_FAILURE);
  }
  struct dirent *direct;
  int detect = 0;

  while ((direct = readdir(directory)) != NULL) {
    if (strcmp(direct->d_name, filename) == 0) {
      detect = 1;
      break;
    }
  }
  closedir(directory);
  return detect;
}