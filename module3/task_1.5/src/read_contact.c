#include "main.h"

void read_contact(Contact *contacts, int *num_contacts){

    int fd = open("contact.txt", O_RDWR, 0666);
    if(fd == -1){
        printf("Error: opening file\n");
        return;
    }

    int bytes_read;
    while(bytes_read = read(fd, &(contacts[*num_contacts]), sizeof(Contact))){
        (*num_contacts)++;
    }

    close(fd);
}

