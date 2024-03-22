#include "main.h"



int find_people(Contact *people, int num_contacts){
    int result = 0;
    char name[MAX_LENGHT_NAME];
    char lastname[MAX_LENGHT_NAME];
    printf("Enter fist name and lastname: \n");
    scanf("%s %s", name, lastname);
    for(int i = 0; i < num_contacts; i++){
        if (strcmp(people[i].name.firstname, name) == 0 && strcmp(people[i].name.lastname, lastname) == 0) {
            result = 1;
            printf("---------------------------------\n");
            printf("Firstname: %s\nLastname: %s\nPlace of work: %s\nPosition: %s\n", 
                   people[i].name.firstname, people[i].name.lastname, 
                   people[i].job_placement.company, people[i].job_placement.position);
            
            printf("Phone numbers:\n");
            for (int j = 0; j < MAX_COUNT; j++) {
                printf("- %s\n", people[i].contact.phone_numbers[j]);
            }

            printf("Emails:\n");
            for (int j = 0; j < MAX_COUNT; j++) {
                printf("- %s\n", people[i].contact.emails[j]);
            }

            printf("Social links:\n");
            for (int j = 0; j < MAX_COUNT; j++) {
                printf("- %s\n", people[i].contact.social_links[j]);
            }

            printf("Messenger profiles:\n");
            for (int j = 0; j < MAX_COUNT; j++) {
                printf("- %s\n", people[i].contact.messenger_profiles[j]);
            }

            printf("---------------------------------\n");
    }
    }
        if(!result){
        printf("The contact was not found\n");
        printf("\n");
    }
    return result;
}