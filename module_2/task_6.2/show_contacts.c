#include "main.h"

void show_contact(struct Item *head) {
  struct Item *tmp = head;

  if (tmp == NULL) {
    printf("Contact list is void.\n");
    return;
  }

  do {
    if (tmp->value_id != 0) {
      printf("Contact:\n");
      printf("ID: %d\n", tmp->value_id);
      printf("First Name: %s\n", tmp->name.firstname);
      printf("Last Name: %s\n", tmp->name.lastname);
      printf("Job: %s\n", tmp->job_placement.company);
      printf("Position: %s\n", tmp->job_placement.position);

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

      printf("\n");
    }
    tmp = tmp->next;
  } while (tmp != head);
}