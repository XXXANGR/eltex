#include "main.h"

long double division(long double n, long double k) {
    if (k != 0) {
        return n / k;
    } else {
        printf("Error: k = 0\n");
        return 0.0;
    }
}