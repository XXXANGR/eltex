#include "main.h"



void save_contact(Contact *contacts, int num_contacts){

    int fd = open("contact.txt", O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("Error: openning file:\n");
        return;
    }

    int bytes_write;

    for(int i = 0; i < num_contacts; i++){
        bytes_write = write(fd, &(contacts[i]), sizeof(Contact));
        if(bytes_write != sizeof(Contact)){
            printf("Error: writing file\n");
            close(fd);
            return;
        }
        }
        close(fd);


}
