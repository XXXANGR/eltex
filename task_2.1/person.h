#ifndef PERSON_H
#define PERSON_H


typedef struct Person
{
    char firstname[MAX_LENGHT_NAME];
    char lastname[MAX_LENGHT_NAME];
    char job[MAX_LENGHT_JOB];
    char phone[MAX_LENGHT_CONTACTS];
}Person;


#endif