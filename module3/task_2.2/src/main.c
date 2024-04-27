#include "main.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: %s numbers\n", argv[0]);
        return 1;
    }

    int num_numbers = atoi(argv[1]);
    if (num_numbers <= 0) {
        printf("Enter a positive integer\n");
        return 1;
    }

    pid_t pid;
    int pipefd[2];
    int rv;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0: 
            child_process(pipefd);
        default: 
            parent_process(pipefd, num_numbers);
            wait(&rv);
    }

    return 0;
}
