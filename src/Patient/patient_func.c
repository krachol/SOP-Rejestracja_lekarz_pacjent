#include "patient.h" 


//running console interface
int runInterface(int server_id, int ID) {
    while (1){
        printf("Co chcesz robić?\n1.Logowanie\n2.Rejestracja\n");
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1: {
                        if (login(server_id, ID)) {
                            printf("You're logged in\n");
                        } else {
                            printf("Zły login, lub hasło\n");
                            continue;
                        }
                        break;
                    }
            case 2: {
                        printf ("Exiting for now\n");
                        exit(1);
                        break;
                    }
        }
    }

    return 0;
}

/* Communication functions */
/* Patient -> Registration */
int login(int server_id, int myID) {
    Message message;
    char login[LOGIN_SIZE];
    char password[PASSWORD_SIZE];

        printf("Input login\n");
        scanf("%s", login);

        printf("Input password\n");
        scanf("%s", password);

        generalLogin(server_id, PATIENT, myID, login, password);

        int messageType = myID << 6;
        messageType = messageType | LOGIN_INFO_REG_TO_PAT_MSG;

        printf("%d\n", messageType);
        message = receiveMessage(server_id, messageType);

    if (message.login_info_message.status)
        return 0;

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
