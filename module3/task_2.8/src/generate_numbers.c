#include "main.h"

void generate_numbers(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; i++) {
        int number = rand() % 100; 
        fprintf(file, "%d\n", number);
    }

    fclose(file);
}