#include "main.h"


void edit_contact(struct Item *head) {
  int id_edit;
  printf("Enter the id of the contact to edit: ");
  scanf("%d", &id_edit);

  struct Item *tmp = head;
  while (tmp != NULL && tmp->value_id != id_edit) {
    tmp = tmp->next;
  }

  if (tmp == NULL) {
    printf("Contact with id %d not found.\n", id_edit);
    return;
  }

  printf("Editing contact with id %d:\n", id_edit);
  enter_data(tmp);
}