#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void child_process(int pipefd[2]);
void parent_process(int pipefd[2], int num_numbers);
#endif