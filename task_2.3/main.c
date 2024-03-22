#include "main.h"

int main() {
    long double n, k;
    char str[5];
    long double (*operation[])(long double, long double) = {addition, subtraction, multiplication, division};
    while (1) {
        printf("Enter 2 number: \n");
        scanf("%Lf %Lf", &n, &k);
        getchar();
        choice_operation();
        fgets(str, 5, stdin);

        long double (*choice_oper)(long double, long double);

        switch (str[0]) {
            case '+':
                choice_oper = operation[0];
                break;
            case '-':
                choice_oper = operation[1];
                break;
            case '*':
                choice_oper = operation[2];
                break;
            case '/':
                choice_oper = operation[3];
                break;
            default:
                printf("Error: enter another operation\n");
                continue;
        }

        long double result = choice_oper(n, k);
        printf("result: %Lf\n", result);
    }

    return 0;
}
