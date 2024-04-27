#include "main.h"

int convert_bits(char *access_rights){
    int bit = 0;

    for(size_t i = 0; i < strlen(access_rights); i++){ 
        if(access_rights[i] == 'r'){
            bit |= (1 << 8) ; 
        }else if(access_rights[i] == 'w'){
            bit |= (1 << 7); 
        }else  if(access_rights[i] == 'x'){
            bit |= (1 << 6); 
        }else{
            printf("Error: %c", access_rights[i]);
            bit = -1;
            return bit;
        }


        }
        printf("\n");
        

    return bit;
}