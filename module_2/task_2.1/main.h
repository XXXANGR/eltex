#ifndef MAIN_H
#define MAIN_H

#define MAX_LENGHT_NAME 20
#define MAX_COUNT 5
#define MAX_LENGHT_CONTACTS 30
#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include "job.h"
#include "contact.h"
#include "person.h"



typedef struct Contact{
    Person name;
    job job_placement;
    Contact_info contact;
} Contact;

int find_people(Contact *people, int num_contacts);
void add_contact(Contact *contact, int *num_contacts);
void choice();
void delete_contact(Contact *contacts, int *numContacts);
int show_list_contacts(Contact *people, int num_contacts);
void edit_contact(Contact *contacts, int num_contacts);


#endif