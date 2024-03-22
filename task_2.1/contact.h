#ifndef CONTACT_H
#define CONTACT_H


typedef struct Contact_info{
    char phone_numbers[MAX_COUNT][MAX_LENGHT_CONTACTS];
    char emails[MAX_COUNT][MAX_LENGHT_CONTACTS];
    char social_links[MAX_COUNT][MAX_LENGHT_CONTACTS];
    char messenger_profiles[MAX_COUNT][MAX_LENGHT_CONTACTS];
} Contact_info;

#endif