#include "main.h"


void add_contact(struct Item *head, int *id_person) {
  if (*id_person >= MAX_CONTACTS) {
    printf("Contact list is full.\n");
    return;
  }
  head = InsertValue(*id_person + 1, head);
  (*id_person)++;
}