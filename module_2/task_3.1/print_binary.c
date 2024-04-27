#include "main.h"



void print_binary(int num){
    int binary[32];
    int index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num = num / 2;
    }

    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}