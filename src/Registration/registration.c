#include "registration.h"

int main ()
{
    int input_msg_ipc_id = -1;
    input_msg_ipc_id = msgget(0xCAFEBABE, 0700 | IPC_CREAT );
    if (input_msg_ipc_id == -1) {
        return 1;
    }

    int clientCounter = 0;

    while (1) {
        checkConnectionRequests(input_msg_ipc_id, &clientCounter);
        login(input_msg_ipc_id);
    }


    msgctl(input_msg_ipc_id, IPC_RMID, NULL);
    input_msg_ipc_id = -1;
    return 0;
}
