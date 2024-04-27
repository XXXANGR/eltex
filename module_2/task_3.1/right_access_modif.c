#include "main.h"


void right_access_modif(){
    int modif;
    printf("Modify access rights: ");
    scanf("%o", &modif);
    printf("bit representation: %o\n", modif);
    printf("Access rights for: \n");
    user_access_rights(modif);


}