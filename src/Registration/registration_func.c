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

void login() {
    return;
}

void logout() {
    return;
}

void registerUser() {
    return;
}

/* Registration -> Patient */
void registerVisit() {
    return;
}

void sendDoctorListForCurrentDay() {
    return;
}

void sendAvailableVisitsForCurrentDay() {
    return;
}

void sendVisitStatus() {
    return;
}

void cancelVisit() {
    return;
}

void sendInfoAboutLoginTries() {
    return;
}

/* Registration -> Doctor */
void registekActualVisit() {
    return;
}

void registerVacation() {
    return;
}
