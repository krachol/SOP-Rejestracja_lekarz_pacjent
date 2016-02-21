#include "patient.h" 


//running console interface
int runInterface(int server_id, int ID) {
    login(server_id, ID);

    return 0;
}

/* Communication functions */
/* Patient -> Registration */
void login(int server_id, int myID) {
    char login[LOGIN_SIZE];
    char password[PASSWORD_SIZE];
    scanf("%s", login);
    scanf("%s", password);

    generalLogin(server_id, PATIENT, myID, login, password);

    return;
}

void logout() {
    return;
}

void registerVisit() {
    return;
}

void getDoctorListForCurrentDay() {
    return;
}

void getAvailableVisitsForCurrentDay() {
    return;
}

void getVisitStatus() {
    return;
}

void cancelVisit() {
    return;
}

void getFailedLoginsNumber() {
    return;
}
