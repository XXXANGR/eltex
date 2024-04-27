#include "main.h"

void parent_process(int pipefd[2], int num_numbers) {
    close(pipefd[0]);
    for (int i = 0; i < num_numbers; ++i) {
        int number = rand() % 1000;
        printf("Родительский процесс отправляет: %d\n", number);
        write(pipefd[1], &number, sizeof(number));
        read(pipefd[0], &number, sizeof(number));
        printf("Родительский процесс получил ответ: %d\n", number);
    }
    close(pipefd[1]);
}