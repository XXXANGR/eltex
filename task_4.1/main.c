#include "main.h"

int main() {
  struct Item *head = NULL;
  head = InsertValue(0, head);
  int n;
  int id_person = 0;

  while (1) {
    choice();
    printf("Enter number: \n");
    if(scanf("%d", &n) != 1){
        printf("incorrect data\n");
        return 1;
    }
    switch (n) {
    case 1:
      add_contact(head, &id_person);
      break;
    case 2:
      delete_contact(head);
      break;
    case 3:
      show_contact(head);
      break;
    case 4:
      edit_contact(head);
      break;
    case 5:
      find_people(head);
      break;
    default:
        printf("incorrect data\n");
    }
  }
  return 0;
}