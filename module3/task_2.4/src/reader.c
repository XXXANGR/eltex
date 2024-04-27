#include "read.h"

int main() {
    int fd_fifo;
    int numbers;
    char *my_fifo = "my_fifo";

    if ((fd_fifo = open(my_fifo, O_RDONLY)) == -1) {
        fprintf(stderr, "Невозможно открыть fifo\n");
        exit(0);
    }

    while (read(fd_fifo, &numbers, sizeof(numbers)) > 0) {
        printf("%d\n", numbers);
    }

    close(fd_fifo);

    return 0;
}
