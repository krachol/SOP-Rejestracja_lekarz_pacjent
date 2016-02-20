//A simple program that calculates square root of number
#include "registration.h"

int main ()
{
    int input_msg_ipc_id = -1;
    input_msg_ipc_id = msgget(0xCAFEBABE, 0700 | IPC_CREAT | IPC_EXCL);
    if (input_msg_ipc_id == -1) {
        return 1;
    }

    sleep(10);
    int end = 0;


    while (!end) {
        end = 1;
    }

    msgctl(input_msg_ipc_id, IPC_RMID, NULL);
    input_msg_ipc_id = -1;
    return 0;
}
