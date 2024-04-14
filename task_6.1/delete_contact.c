#include "main.h"


void delete_contact(struct Item *head) {
    printf("Enter id contact to delete: \n");
    int id_del;
    scanf("%d", &id_del);
    head = DeleteValue(id_del, head);
    clear_window();
}