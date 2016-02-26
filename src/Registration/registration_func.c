#include "registration.h"

void checkConnectionRequests(int server_id, int* clientCounter) {
    Message message;
    int rVal = -1;
    /* odbierz wiadomość o połączeniu od klienta */
    rVal = msgrcv (
            server_id,
            (void*)(&message.base_message),
            sizeof(message.base_message) - sizeof(long), 
            CONNECT_CLIENT_TO_REG_MSG,
            IPC_NOWAIT
            );
    /* przydziel mu numer i wyślij w wiadomości zwrotnej */
    if (rVal != -1) {
        message.connect_info_message.type = CONNECT_INFO_REG_TO_CLIENT_MSG;
        message.connect_info_message.number = *clientCounter;
        int rVal = msgsnd (
                server_id, 
                &message.base_message, 
                sizeof(message.base_message) - sizeof(long), 
                IPC_NOWAIT
                );
        if (fork() == 0) {
            if ( rVal == -1) {
                printf("Waiting for space in message queue\n");
                msgsnd (
                        server_id, 
                        (void*)(&message.base_message), 
                        sizeof(message.base_message) - sizeof(long), 
                        0
                       );
            }
            exit(0);
        }
        (*clientCounter)++;
    }

    return ;
}

/* Communication functions */
void registrationSendMessage(int server_id, int clientID, Message message) {
    message.base_message.type = ((clientID << 6) | message.base_message.type);
    int rVal = msgsnd (
            server_id, 
            &message.base_message, 
            sizeof(message.base_message) - sizeof(long), 
            IPC_NOWAIT
            );
    if (fork() == 0) {
        if ( rVal == -1) {
            printf("Waiting for space in message queue\n");
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

        Message response;

        switch (message.login_message.sender) {
            case PATIENT:
                response.login_info_message.type = LOGIN_INFO_REG_TO_PAT_MSG;
                break;
            case DOCTOR:
                response.login_info_message.type = LOGIN_INFO_REG_TO_DOC_MSG;
                break;
        }

        if ((findByID(message.login_message.ID) == NULL) &&
                (findByLogin(message.login_message.login) == NULL)) {

            addLoggedInUser(
                    message.login_message.login,
                    message.login_message.ID
                    );

            response.login_info_message.status = OK;
        } else {
            response.login_info_message.status = NOT_OK;
        }
        registrationSendMessage ( 
                server_id, 
                message.login_message.ID, 
                response
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
