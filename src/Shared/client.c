#include "client.h"


//Establish connection
int connect(int* id) { 

    while (-1 == (*id = msgget(0xCAFEBABE, 0700))) {
        printf("Haven't been able to connect. Trying again in 1 second\n");
        sleep(1);
    }

    return 1;
}


int generalLogin (int server_id, int sender, char* login, char* password) {
    Message message;

    message.login_message.type = LOGIN_CLIENT_TO_REG_MSG;
    message.login_message.sender = sender;
    sprintf(message.login_message.login, "%s", login);
    sprintf(message.login_message.password, "%s", password);

   int rVal = msgsnd (
            server_id, 
            &message.base_message, 
            sizeof(message.base_message) - sizeof(long), 
            IPC_NOWAIT
        );

    if ( rVal == -1) {
        printf("Waiting for space in queue\n");
        msgsnd (
                server_id, 
                (void*)(&message.base_message), 
                sizeof(message.base_message) - sizeof(long), 
                0
               );
    }

    return 1;
}
