#include "main.h"

void read_directory(char *directory_name) {
    DIR *directory = opendir(directory_name);
    if (directory == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    } 

    struct dirent *direct;
    struct stat filestat;
    char full_path[MAX_PATH_LENGTH];

    while ((direct = readdir(directory)) != NULL) {
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", directory_name, direct->d_name);

        if (stat(full_path, &filestat) < 0) {
            perror("Error: failed to get the file status");
            closedir(directory);
            exit(EXIT_FAILURE);
        }

        printf("---------------------\n");
        printf("File: %s\nSymbolic link: %d\nRegular file: %d\nDirectory: %d\nCharacter device: %d\nBlock device: %d\nFIFO channel: %d\nSocket: %d\n",
               direct->d_name, S_ISLNK(filestat.st_mode), S_ISREG(filestat.st_mode),
               S_ISDIR(filestat.st_mode), S_ISCHR(filestat.st_mode), S_ISBLK(filestat.st_mode),
               S_ISFIFO(filestat.st_mode), S_ISSOCK(filestat.st_mode));
    }
    closedir(directory);
}