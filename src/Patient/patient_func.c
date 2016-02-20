#include "patient.h" 

int connect(int* id) 
{ 
    *id = msgget(0xCAFEBABE, 0700);

    if (*id == -1)
        return 0; 

    return 1;
}

int runInterface() {
    return 1;
}

void disconnect(int* id){
    msgctl(*id, IPC_RMID, NULL);
    return;
}

void login() {
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
