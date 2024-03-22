#include "main.h"



void add_contact(Contact *contact, int *num_contacts){
    if (*num_contacts < MAX_CONTACTS){
    Contact new_contact;

    printf("Enter name: \n");
    scanf("%s", new_contact.name.firstname);

    printf("Enter last name: \n");
    scanf("%s", new_contact.name.lastname);

    printf("Enter place of work: \n");
    scanf("%s", new_contact.job_placement.company);
    
    printf("Enter position: \n");
    scanf("%s", new_contact.job_placement.position);

    for (int i = 0; i < MAX_COUNT; i++) {
        strcpy(new_contact.contact.phone_numbers[i], "");
        strcpy(new_contact.contact.emails[i], "");
        strcpy(new_contact.contact.social_links[i], "");
        strcpy(new_contact.contact.messenger_profiles[i], "");
    }

    printf("Enter phone number: \n");
    int count = 0;
    while (count < MAX_COUNT){
        printf("Phone number %d: ", count + 1);
        scanf("%s", new_contact.contact.phone_numbers[count]);
        if (strcmp(new_contact.contact.phone_numbers[count], "-") == 0)
            break;
        count++;
    }

    count = 0;
    printf("Enter email: \n");
    while (count < MAX_COUNT){
        printf("Email %d: ", count + 1);
        scanf("%s", new_contact.contact.emails[count]);
        if (strcmp(new_contact.contact.emails[count], "-") == 0)
            break;
        count++;
    }

    count = 0;
    printf("social links: \n");
    while (count < MAX_COUNT){
        printf("Phone number %d: ", count + 1);
        scanf("%s", new_contact.contact.social_links[count]);
        if (strcmp(new_contact.contact.social_links[count], "-") == 0)
            break;
        count++;
    }

    count = 0;
    printf("Enter messenger profiles: \n");
    while (count < MAX_COUNT){
        printf("Phone number %d: ", count + 1);
        scanf("%s", new_contact.contact.messenger_profiles[count]);
        if (strcmp(new_contact.contact.messenger_profiles[count], "-") == 0)
            break;
        count++;
    }

    contact[*num_contacts] = new_contact;
    (*num_contacts)++;

    }else
    printf("list contact full: \n");
}