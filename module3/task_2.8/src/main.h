#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern int file_locked;

void signal_handler(int signal);
void child_process(int pipe_fd[2], FILE *file);
void parent_process(int pipe_fd[2], FILE *file, pid_t pid);

#endif