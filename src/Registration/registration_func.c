#include "registration.h"

void checkConnectionRequests(int input_msg_ipc_id, int* clientCounter) {
    Message message;
    int rVal = -1;
    rVal = msgrcv (
            input_msg_ipc_id,
            (void*)(&message.base_message),
            sizeof(message.base_message) - sizeof(long), 
            CONNECT_CLIENT_TO_REG_MSG,
            IPC_NOWAIT
            );
    if (rVal != -1) {
        message.connect_info_message.type = CONNECT_INFO_REG_TO_CLIENT_MSG;
        message.connect_info_message.number = *clientCounter;
        registrationSendMessage(input_msg_ipc_id, message); 
        (*clientCounter)++;
    }

    return ;
}

/* Communication functions */
void registrationSendMessage(int server_id, Message message) {
    int rVal = msgsnd (
            server_id, 
            &message.base_message, 
            sizeof(message.base_message) - sizeof(long), 
            IPC_NOWAIT
            );
    if (fork() == 0) {
        if ( rVal == -1) {
            printf("Waiting for space in queue\n");
            msgsnd (
                    server_id, 
                    (void*)(&message.base_message), 
                    sizeof(message.base_message) - sizeof(long), 
                    0
                   );
        }
        exit(0);
    }

    return;
}
/* Registration -> * */

void login(int server_id) {
    Message message;

    int rVal = -1;

    rVal = msgrcv (
            server_id,
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

    return;
}

void logout(int server_id) {
    return;
}

void registerUser(int server_id) {
    return;
}

/* Registration -> Patient */
void registerVisit(int server_id) {
    return;
}

void sendDoctorListForCurrentDay(int server_id) {
    return;
}

void sendAvailableVisitsForCurrentDay(int server_id) {
    return;
}

void sendVisitStatus(int server_id) {
    return;
}

void cancelVisit(int server_id) {
    return;
}

void sendInfoAboutLoginTries(int server_id) {
    return;
}

/* Registration -> Doctor */
void registekActualVisit(int server_id) {
    return;
}

void registerVacation(int server_id) {
    return;
}
