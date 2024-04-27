#include "main.h"


void user_access_rights(mode_t buf){

        printf("access to the file by the owner: \n");          // S_IRUSR, S_IWUSR, S_IXUSR и тд. представляют собой маски в структуре st_mode
        printf(buf & S_IRUSR ? "r" : "-");                      // S_IRUSR 00400 Владелец файла имеет разрешение на чтение
        printf(buf & S_IWUSR ? "w" : "-");                      // S_IWUSR 00200 владелец файла имеет разрешение на запись
        printf(buf & S_IXUSR ? "x" : "-");                      // S_IXUSR 00100 Владелец файла имеет права на исполнение
        printf("\n");

        printf("access to the file by the group: \n");
        printf(buf & S_IRGRP ? "r" : "-");                      // S_IRGRP Бит разрешения на чтение для владельца группы файла. Обычно 040.
        printf(buf & S_IWGRP ? "w" : "-");                      // S_IWGRP Бит разрешения на запись для владельца группы файла. Обычно 020.
        printf(buf & S_IXGRP ? "x" : "-");                      // S_IXGRP Бит разрешения на выполнение или поиск для владельца группы файла. Обычно 010.
        printf("\n");

        printf("access to the file by the ohter user: \n");
        printf(buf & S_IROTH ? "r" : "-");                      // S_IROTH 00004 Другие пользователи имеют разрешение на чтение
        printf(buf & S_IWOTH ? "w" : "-");                      // S_IWOTH 00002 Другие пользователи имеют разрешение на запись
        printf(buf & S_IXOTH ? "x" : "-");                      // S_IXOTH 00001 Другие пользователи имеют права на выполнение
        printf("\n");
}