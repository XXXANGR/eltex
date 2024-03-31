#include "main.h"

int main() {

    char access_rights[10];
    int bits;
    char path[100];
    struct stat buf;

    printf("Enter the access rights: ");
    scanf("%s", access_rights);

    if (access_rights[0] >= '0' && access_rights[0] <= '7') {
        bits = atoi(access_rights);
        printf("Bit representation: %d\n", bits);
        print_binary(bits);
    } else {
        bits = convert_bits(access_rights);
        printf("Bit representation: %o\n", bits);
        print_binary(bits);
    }

    printf("Enter the path: \n");

    scanf("%s", path);
    stat(path, &buf);
    printf("Path: %s\nbits: %d\n", path, buf.st_mode & 0777); // выполняем побитовое "или", двоичное представление числа 0777 будет 111111 то есть будет как маска

    printf("access rights for: \n");
    user_access_rights(buf.st_mode);

    right_access_modif();
    return 0;
}
