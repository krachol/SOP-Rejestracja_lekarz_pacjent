#include "client.h"


//Establish connection
int connect(int* id) { 

    while (-1 == (*id = msgget(0xCAFEBABE, 0700))) {
        printf("Haven't been able to connect. Trying again in 1 second\n");
        sleep(1);
    }


    int clientnumber;
   
    Message message;
    message.connect_message.type = CONNECT_CLIENT_TO_REG_MSG;
    sendMessage(*id, message);
    
    message = receiveMessage(*id, CONNECT_INFO_REG_TO_CLIENT_MSG);
    clientnumber = message.connect_info_message.number;
    
    return clientnumber;
}

Message receiveMessage(int server_id, long type) {
    Message message;

    int rVal = msgrcv (
            server_id, 
            &message.base_message, 
            sizeof(message.base_message) - sizeof(long), 
            type,
            IPC_NOWAIT
            );


    if ( rVal == -1) {
        printf("Waiting for message\n");
        msgrcv (
                server_id, 
                (void*)(&message.base_message), 
                sizeof(message.base_message) - sizeof(long), 
                type,
                0
               );
    }

    return message;
}

void sendMessage(int server_id, Message message) {

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

    return;
}

int generalLogin (int server_id, int sender, int ID, char* login, char* password) {
    Message message;

    message.login_message.type = LOGIN_CLIENT_TO_REG_MSG;
    message.login_message.sender = sender;
    message.login_message.ID = ID;
    sprintf(message.login_message.login, "%s", login);
    sprintf(message.login_message.password, "%s", password);

    sendMessage(server_id, message);
    return 1;
}
