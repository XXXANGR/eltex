#include "client.h"


int main() {
    struct msgbuf msg;
    key_t key = get_key("msg_queue", 'A');
    int msgid = get_msg_queue_id(key);

    printf("Pid client %d\n", getpid());
    printf("Enter message (exit to stop):\n");

    while (1) {
        printf(">>: ");
        fgets(msg.mtext, sizeof(msg.mtext), stdin);

        if (strcmp(msg.mtext, "exit\n") == 0) {
            printf("You have completed the chat.\n");
            break;
        }

        send_msg(msgid, &msg);
        receive_msg(msgid, &msg);
        printf("Server: %s\n", msg.mtext);
    }

    return 0;
}
