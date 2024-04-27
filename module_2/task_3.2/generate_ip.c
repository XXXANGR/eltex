#include "main.h"

void generat_ip(int num_packets, char packets[][IP_LENGTH], float * count_subnet, char *ip_src, char *mask){
    for (int i = 0; i < num_packets; i++) {
        sprintf(packets[i], "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
        // sprintf(packets[i], "%d.%d.%d.%d", 192, 168, 0, 1);

        if (check_subnet(packets[i], ip_src, mask)) {
            (*count_subnet)++;
        }
    }


}