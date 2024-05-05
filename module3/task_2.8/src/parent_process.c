#include "main.h"

void parent_process(FILE *file, int pipe_fd[2], pid_t child_pid) {
    printf("Parent pid = %d\n", getpid());
    close(pipe_fd[1]);
    int number;
    while (read(pipe_fd[0], &number, sizeof(number)) > 0) {
        printf("Родительский процесс %d: прочитано число из канала: %d\n", getpid(), number);
        printf("Блокирует перед изменением\n");
        kill(child_pid, SIGUSR1);
        waitpid(child_pid, NULL, 0);
        while (file_locked) {
        }
        fprintf(file, "%d\n", number);
        printf("записываем число: %d в файл\n", number);
        printf("Разблокирует после изменения\n");
        kill(child_pid, SIGUSR2);
    }
    close(pipe_fd[0]);
    waitpid(child_pid, NULL, 0);
}