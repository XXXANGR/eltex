#include "main.h"


void delete_contact(Contact *contacts, int *numContacts) {
    char firstname[MAX_LENGHT_NAME];
    char lastname[MAX_LENGHT_NAME];
    printf("Enter firstname and lastname: ");
    scanf("%s %s", firstname, lastname);

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name.firstname, firstname) == 0 &&
            strcmp(contacts[i].name.lastname, lastname) == 0) {
            memset(&contacts[i], 0, sizeof(Contact));
            printf("Contact delete!\n");
            return;
        }
    }
    printf("Contact not found\n");
}