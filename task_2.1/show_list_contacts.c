#include "main.h"

int show_list_contacts(Contact *people, int num_contacts)
{
	if (people == NULL || num_contacts == 0)
	{
		 printf ("Contact list void \n");
		return 1;
	}

	for (int i = 0; i < num_contacts; i++)
	{
		printf("Fistname: %s\n", people[i].name.firstname);
		printf("Lastname: %s\n", people[i].name.lastname);
		printf("place of work: %s\n", people[i].job_placement.company);
		printf("Position: %s\n", people[i].job_placement.position);

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
        
        printf("\n");
	}
	printf("\n");
        return 0;
}