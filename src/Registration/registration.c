//A simple program that calculates square root of number
#include "registration.h"

int main ()
{
    int input_msg_ipc_id = -1;
    input_msg_ipc_id = msgget(0xCAFEBABE, 0700 | IPC_CREAT);
    if (input_msg_ipc_id == -1) {
        return 1;
    }

    Message message;
    int clientCounter = 0;

    int rVal = -1;
    while (1) {
        rVal = -1;
        rVal = msgrcv (
                input_msg_ipc_id,
                (void*)(&message.base_message),
                sizeof(message.base_message) - sizeof(long), 
                CONNECT_CLIENT_TO_REG_MSG,
                IPC_NOWAIT
               );
        if (rVal != -1) {
            message.connect_info_message.type = CONNECT_INFO_REG_TO_CLIENT_MSG;
            message.connect_info_message.number = clientCounter;
            registrationSendMessage(input_msg_ipc_id, message); 
            clientCounter++;
        }
        rVal = -1;
        rVal = msgrcv (
                input_msg_ipc_id,
                (void*)(&message.base_message),
                sizeof(message.base_message) - sizeof(long), 
                LOGIN_CLIENT_TO_REG_MSG,
                IPC_NOWAIT
               );
        if (rVal != -1) {
            printf("%d\n%d\n%s\n%s\n",
                    message.login_message.ID,
                    message.login_message.sender,
                    message.login_message.login,
                    message.login_message.password
                    );
        }
    }

    msgctl(input_msg_ipc_id, IPC_RMID, NULL);
    input_msg_ipc_id = -1;
    return 0;
}
