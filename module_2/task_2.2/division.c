#include "main.h"

void division(long double n, long double k){
    if (k == 0) {
    printf("Error: k = 0 \n");
        return;
    }
    long double result = n / k;
    printf("result %Lf / %Lf = %Lf\n", n, k, result);
}