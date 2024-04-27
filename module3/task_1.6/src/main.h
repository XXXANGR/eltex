#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1000
void read_directory(char *directory_name);

#endif