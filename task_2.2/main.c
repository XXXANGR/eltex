
#include "main.h"

int main (){
    long double n, k;
    char str[5];
    while(1){
        printf("Введите 2 числа: \n");
        if(scanf("%Lf %Lf", &n, &k) != 2){
            printf("Ошибка: некорректные данные\n");
            return 1;
        }
        getchar();
        choice_operation();
        printf("Введите операцию:\n");
        fgets(str, 5, stdin);

        switch (str[0]){
            case '+':
                addition(n, k);
                break;
            case '-':
                subtraction(n, k);
                break;
            case '*':
                multiplication(n, k);
                break;
            case '/':
                division(n, k);
                break;
            default:
                printf("Ошибка: недопустимая операция\n");
                break;
        }
    }

    return 0;
}