#include "main.h"

int file_locked = 0;

int main() {
    char *filename = "numbers.txt";
    generate_numbers(filename);

    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    if (pid == 0) {
        child_process(file, pipe_fd);
    } else {
        parent_process(file, pipe_fd, pid);
    }

    fclose(file);
    return 0;
}