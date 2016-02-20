#include "patient.h" 

//Establish connection
int connect(int* id) { 
    *id = msgget(0xCAFEBABE, 0700);

    if (*id == -1)
        return 0; 

    return 1;
}

//running console interface
int runInterface() {
    return 0;
}

/* Communication functions */
/* Patient -> Registration */
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
