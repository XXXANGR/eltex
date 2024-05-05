#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern int file_locked;

void signal_handler(int sig);
void generate_numbers(char *filename);
void parent_process(FILE *file, int pipe_fd[2], pid_t child_pid);
void child_process(FILE *file, int pipe_fd[2]);
#endif