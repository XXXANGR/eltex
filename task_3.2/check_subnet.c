#include "main.h"

int check_subnet(char* ip, char* ip_src, char* mask) {

    int result = 1;
    int ip_octets[4], ip_src_octets[4], mask_octets[4], net_src[4], net_dst[4];

    // Разбиение IP адресов на октеты
    sscanf(ip, "%d.%d.%d.%d", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);
    sscanf(ip_src, "%d.%d.%d.%d", &ip_src_octets[0], &ip_src_octets[1], &ip_src_octets[2], &ip_src_octets[3]);
    sscanf(mask, "%d.%d.%d.%d", &mask_octets[0], &mask_octets[1], &mask_octets[2], &mask_octets[3]);

    // Опеределяем адрес сети назначения и адрес своей сети
    for (int i = 0; i < 4; i++) {
        net_src[i] = ip_octets[i] & mask_octets[i];
        net_dst[i] = ip_src_octets[i] & mask_octets[i];
    }
    
    // проверяем, совпадает ли адрес сетей (0 - ОК, 1 - другой)
    for(int i = 0; i < 4; i++)
            if (net_src[i] ^ net_dst[i]) {
            result = 0; 
        }
    return result;
}