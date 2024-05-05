#include "main.h"

void child_process(FILE *file, int pipe_fd[2]) {
    printf("Child pid = %d\n", getpid());
    close(pipe_fd[0]);
    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        printf("Дочерний процесс %d: прочитано число из файла: %d\n", getpid(), number);
        write(pipe_fd[1], &number, sizeof(number));
        kill(getppid(), SIGUSR2);
    }
    close(pipe_fd[1]);
    fclose(file);
    exit(EXIT_SUCCESS);
}