#include "main.h"

void child_process(int pipefd[2]) {
    close(pipefd[1]);
    int number;
    while (read(pipefd[0], &number, sizeof(number)) > 0) {
        printf("Дочерний процесс прочитал: %d\n", number);
        number *= 2; 
        write(pipefd[1], &number, sizeof(number));
        printf("Отправлено обратно: %d\n", number);
    }
    close(pipefd[0]);
    exit(EXIT_SUCCESS);
}