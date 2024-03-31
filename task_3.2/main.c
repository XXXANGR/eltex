#include "main.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: %s ip_src mask num_packets\n", argv[0]);
        return 1;
    }

    char* ip_src = argv[1];
    char* mask = argv[2];
    int num_packets = atoi(argv[3]);

    if (num_packets > MAX_PACKETS || num_packets <= 0) {
        printf("Error: Number of packets should be positive and at most %d\n", MAX_PACKETS);
        return 1;
    }

    char packets[MAX_PACKETS][IP_LENGTH];
    float count_subnet = 0;

    // Generating random IP addresses
    generat_ip(num_packets, packets, &count_subnet, ip_src, mask);

    printf("Total number of packages: %d\n", num_packets);
    printf("Packets destined for the same subnet: %g (%.2f %%)\n", count_subnet, count_subnet / num_packets * 100);
    printf("Packets destined for other subnets: %g (%.2f %%)\n", num_packets - count_subnet, (num_packets - count_subnet) / num_packets * 100);

    return 0;
}

