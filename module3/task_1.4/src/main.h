#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGHT_STRING 100
#define MAX_ARGUMENT 100


int detect_file(char *filename);
#endif