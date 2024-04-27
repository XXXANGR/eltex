#include "main.h"



int main() {
    char directory_name[MAX_PATH_LENGTH];
    printf("Enter directory path (symbol '.' for current directory): ");
    if (fgets(directory_name, sizeof(directory_name), stdin) == NULL) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(directory_name);
    if (directory_name[len - 1] == '\n') {
        directory_name[len - 1] = '\0';
    }

    read_directory(directory_name);

    return 0;
}
