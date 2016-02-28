#include "patient.h" 

//running console interface
int runInterface(int server_id, int ID) {
    int input = -1;
    int isLoggedIn = 0;

    while (!isLoggedIn){
        printf("Co chcesz robić?\n1.Logowanie\n2.Wyjście\n");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                        if (login(server_id, ID)) {
                            printf("You're logged in\n");
                            isLoggedIn = 1;
                        } else {
                            printf("Zły login, lub hasło\n");
                            continue;
                        }
                        break;
                    }

            case 2: {
                        printf ("Exiting for now\n");
                        return 0;
                        break;
                    }
        }
    }

    while (isLoggedIn) {
        printf("Co chcesz zrobić?\n"
                "1. Zarejestruj wizytę\n"
                "2. Wyloguj i zamknij\n"
                );
        scanf("%d", &input);

        switch (input) {
            case 1: break;

            case 2: {
                        logout(server_id, ID);
                        return 0;
                    }
        }
    }

    return 0;
}

/* Communication functions */
/* Patient -> Registration */
int login(int server_id, int myID) {
    return generalLogin(server_id, PATIENT, myID);
}


void logout(int server_id, int myID) {
    generalLogout(server_id, myID);
    return;
}


void registerVisit(int server_id, int myID) {
    Message message;

    message.register_visit_mesage.type = REGISTER_VISIT_CLIENT_TO_REG_MSG; 
    message.register_visit_mesage.ID = myID;
    message.register_visit_mesage.sender = PATIENT;
    printf("Podaj imie:\n");
    scanf("%s", message.register_visit_mesage.name);
    printf("Podaj nazwisko:\n");
    scanf("%s", message.register_visit_mesage.surname);
    printf("Podaj PESEL:\n");
    scanf("%s", message.register_visit_mesage.PESEL);
    

    printf("Podaj rok wizyty:\n");
    scanf("%d", &message.register_visit_mesage.timeanddate.tm_year);
    
    printf("Podaj miesiąc wizyty:\n");
    scanf("%d", &message.register_visit_mesage.timeanddate.tm_mon);

    printf("Podaj dzień wizyty:\n");
    scanf("%d", &message.register_visit_mesage.timeanddate.tm_mday);

    sendMessage(server_id, message);
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
