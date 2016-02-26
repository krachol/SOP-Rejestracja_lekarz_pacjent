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

int generalLogin (int server_id, int sender, int ID) {
    Message message;

    char login[LOGIN_SIZE];
    char password[PASSWORD_SIZE];

    printf("Input login\n");
    scanf("%s", login);

    printf("Input password\n");
    scanf("%s", password);

    message.login_message.type = LOGIN_CLIENT_TO_REG_MSG;
    message.login_message.sender = sender;
    message.login_message.ID = ID;
    sprintf(message.login_message.login, "%s", login);
    sprintf(message.login_message.password, "%s", password);

    sendMessage(server_id, message);

    int messageType = ID << 6;
    switch (sender) {
        case DOCTOR:
            messageType = messageType | LOGIN_INFO_REG_TO_DOC_MSG;
            break;
        case PATIENT:
            messageType = messageType | LOGIN_INFO_REG_TO_PAT_MSG;
            break;
        default:
            return 0;
    }
    
    message = receiveMessage(server_id, messageType);

    if (message.login_info_message.status)
        return 0;

    return 1;
}
