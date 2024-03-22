#include "main.h"

int main(){
    Contact people[MAX_CONTACTS];
    int n;
    int num_contacts = 0;
    while(1){
        choice();
        printf("Enter number: \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        add_contact(people, &num_contacts);
            break;
        case 2:
        delete_contact(people, &num_contacts);
            break;
        case 3:
        edit_contact(people, num_contacts);
            break;
        case 4:
        find_people(people, num_contacts);
            break;
        case 5:
        show_list_contacts(people, num_contacts);
            break;
        default:
            break;
        }
    }
    return 0;
}