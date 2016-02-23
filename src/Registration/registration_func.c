#include "registration.h"

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
