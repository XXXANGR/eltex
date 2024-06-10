#include "server.h"

int main() {
    char id = 'A';
    char *filename = "msg_queue";
    create_file(filename);
    key_t key = get_key(filename, id);
    int msgid = get_msg_queue_id(key);
    struct msgbuf msg;
    pid_t clients[MAX_CLIENTS] = {0}; 
    int client_count = 0; 

    printf("the server is running.\n");

    while (1) {
        receive_msg(msgid, &msg);
        // printf("client pid %d message: %s", msg.pid, msg.mtext);
        add_client(clients, &client_count, msg.pid);
        char format_msg[MAX_MSG_SIZE + ADD_MSG_SIZE];
        snprintf(format_msg, sizeof(format_msg), "client %d: %s", msg.pid, msg.mtext);
        send_msg_all_clients(msgid, clients, client_count, &msg, format_msg);
    }
    return 0;
}
