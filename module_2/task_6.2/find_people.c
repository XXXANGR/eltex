#include "main.h"



int find_people(Item *head) {
  int result = 0;
  char name[MAX_LENGHT_NAME];
  char lastname[MAX_LENGHT_NAME];
  printf("Enter first name and lastname: \n");
  scanf("%s %s", name, lastname);

  Item *tmp = head;

  do {
    if (strcmp(tmp->name.firstname, name) == 0 &&
        strcmp(tmp->name.lastname, lastname) == 0) {
      result = 1;
      printf("---------------------------------\n");
      printf("ID: %d\n", tmp->value_id);
      printf("First Name: %s\nLast Name: %s\n", tmp->name.firstname,
             tmp->name.lastname);
      printf("Job: %s\nPosition: %s\n", tmp->job_placement.company,
             tmp->job_placement.position);

      printf("Phone numbers:\n");
      for (int j = 0; j < MAX_COUNT; j++) {
        if (strcmp(tmp->contact.phone_numbers[j], "-") != 0 &&
            strcmp(tmp->contact.phone_numbers[j], "") != 0) {
          printf("%s\n", tmp->contact.phone_numbers[j]);
        }
      }

      printf("Emails:\n");
      for (int j = 0; j < MAX_COUNT; j++) {
        if (strcmp(tmp->contact.emails[j], "-") != 0 &&
            strcmp(tmp->contact.emails[j], "") != 0) {
          printf("%s\n", tmp->contact.emails[j]);
        }
      }

      printf("Social links:\n");
      for (int j = 0; j < MAX_COUNT; j++) {
        if (strcmp(tmp->contact.social_links[j], "-") != 0 &&
            strcmp(tmp->contact.social_links[j], "") != 0) {
          printf("%s\n", tmp->contact.social_links[j]);
        }
      }

      printf("Messenger profiles:\n");
      for (int j = 0; j < MAX_COUNT; j++) {
        if (strcmp(tmp->contact.messenger_profiles[j], "-") != 0 &&
            strcmp(tmp->contact.messenger_profiles[j], "") != 0) {
          printf("%s\n", tmp->contact.messenger_profiles[j]);
        }
      }

      printf("---------------------------------\n");
    }
    tmp = tmp->next;
  } while (tmp != head);

  if (!result) {
    printf("The contact was not found\n");
    printf("\n");
  }
  return result;
}