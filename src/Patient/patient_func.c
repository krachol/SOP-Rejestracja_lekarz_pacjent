#include "patient.h" 


//running console interface
int runInterface(int server_id, int ID) {
    if (login(server_id, ID)) {
        printf("You're logged in");
    }

    return 0;
}

/* Communication functions */
/* Patient -> Registration */
int login(int server_id, int myID) {
    char login[LOGIN_SIZE];
    char password[PASSWORD_SIZE];
    scanf("%s", login);
    scanf("%s", password);

    generalLogin(server_id, PATIENT, myID, login, password);

    return 1;
}

void logout(int server_id, int myID) {
    return;
}

void registerVisit(int server_id, int myID) {
    return;
}

void getDoctorListForCurrentDay(int server_id, int myID) {
    return;
}

void getAvailableVisitsForCurrentDay(int server_id, int myID) {
    return;
}

void getVisitStatus(int server_id, int myID) {
    return;
}

void cancelVisit(int server_id, int myID) {
    return;
}

void getFailedLoginsNumber(int server_id, int myID) {
    return;
}
