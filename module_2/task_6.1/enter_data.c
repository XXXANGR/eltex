#include "main.h"


void enter_data(struct Item *newItem) {

  int count = 0;

  printf("Enter first name: ");
  scanf("%s", newItem->name.firstname);

  printf("Enter last name: ");
  scanf("%s", newItem->name.lastname);

  printf("Enter place of work: ");
  scanf("%s", newItem->job_placement.company);

  printf("Enter position: ");
  scanf("%s", newItem->job_placement.position);

  for (int i = 0; i < MAX_COUNT; i++) {
    strcpy(newItem->contact.phone_numbers[i], "");
    strcpy(newItem->contact.emails[i], "");
    strcpy(newItem->contact.social_links[i], "");
    strcpy(newItem->contact.messenger_profiles[i], "");
  }

  printf("Enter phone number, ' - ' - stop: \n");
  while (count < MAX_COUNT) {
    printf("Phone number %d: ", count + 1);
    scanf("%s", newItem->contact.phone_numbers[count]);
    if (strcmp(newItem->contact.phone_numbers[count], "-") == 0)
      break;
    count++;
  }

  count = 0;
  printf("Enter email, ' - ' - stop: \n");
  while (count < MAX_COUNT) {
    printf("Email %d: ", count + 1);
    scanf("%s", newItem->contact.emails[count]);
    if (strcmp(newItem->contact.emails[count], "-") == 0)
      break;
    count++;
  }

  count = 0;
  printf("social links, ' - ' - stop: \n");
  while (count < MAX_COUNT) {
    printf("Phone number %d: ", count + 1);
    scanf("%s", newItem->contact.social_links[count]);
    if (strcmp(newItem->contact.social_links[count], "-") == 0)
      break;
    count++;
  }

  count = 0;
  printf("Enter messenger profiles, ' - ' - stop: \n");
  while (count < MAX_COUNT) {
    printf("Phone number %d: ", count + 1);
    scanf("%s", newItem->contact.messenger_profiles[count]);
    if (strcmp(newItem->contact.messenger_profiles[count], "-") == 0)
      break;
    count++;
  }
  clear_window();
}