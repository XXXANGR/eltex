#include "main.h"



void edit_contact(Contact *contacts, int num_contacts) {
    char firstname[20];
    char lastname[20];
    printf("Enter firstname and lastname: \n");
    scanf("%s %s", firstname, lastname);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name.firstname, firstname) == 0 &&
            strcmp(contacts[i].name.lastname, lastname) == 0) {

            printf("Enter new first name: ");
            scanf("%s", contacts[i].name.firstname);

            printf("Enter new last name: ");
            scanf("%s", contacts[i].name.lastname);

            printf("Enter new place of work: ");
            scanf("%s", contacts[i].job_placement.company);

            printf("Enter new position: ");
            scanf("%s", contacts[i].job_placement.position);

            printf("Enter new phone number: ");
            int count = 0;
            while (count < MAX_COUNT) {
                printf("Phone number %d: ", count + 1);
                scanf("%s", contacts[i].contact.phone_numbers[count]);
                if (strcmp(contacts[i].contact.phone_numbers[count], "-") == 0)
                    break;
                count++;
            }

            printf("Enter new email: ");
            count = 0;
            while (count < MAX_COUNT) {
                printf("Email %d: ", count + 1);
                scanf("%s", contacts[i].contact.emails[count]);
                if (strcmp(contacts[i].contact.emails[count], "-") == 0)
                    break;
                count++;
            }

            printf("Enter new social links: ");
            count = 0;
            while (count < MAX_COUNT) {
                printf("Social links %d: ", count + 1);
                scanf("%s", contacts[i].contact.social_links[count]);
                if (strcmp(contacts[i].contact.social_links[count], "-") == 0)
                    break;
                count++;
            }

            printf("Enter new messenger profiles: ");
            count = 0;
            while (count < MAX_COUNT) {
                printf("Messenger profile %d: ", count + 1);
                scanf("%s", contacts[i].contact.messenger_profiles[count]);
                if (strcmp(contacts[i].contact.messenger_profiles[count], "-") == 0)
                    break;
                count++;
            }
            printf("Contact successfully edited!\n");
            return;
        }else 
            printf("Contact not found\n");
    }

}