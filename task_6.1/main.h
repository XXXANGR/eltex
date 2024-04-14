#ifndef MAIN_H
#define MAIN_H

#define MAX_LENGHT_NAME 20
#define MAX_COUNT 5
#define MAX_LENGHT_CONTACTS 30
#define MAX_CONTACTS 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "job.h"
#include "contact.h"
#include "person.h"



typedef struct Item {
  int value_id;
  Person name;
  job job_placement;
  Contact_info contact;
  struct Item *prev;
  struct Item *next;
} Item;


void clear_window();
void choice();
void enter_data(struct Item *newItem);
int find_people(Item *head);
void show_contact(struct Item *head);
void edit_contact(struct Item *head);
struct Item *DeleteValue(int val, struct Item *head);
struct Item *InsertValue(int val, struct Item *head);
void add_contact(struct Item *head, int *id_person);
void delete_contact(struct Item *head);


#endif