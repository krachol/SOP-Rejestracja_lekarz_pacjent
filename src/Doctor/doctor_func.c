#include "doctor.h"

void runInterface(int server_id, int ID) {
    int loggedIn = 0;
    int input = -1;
    while (!loggedIn){
        printf("Co chcesz robić?\n1.Logowanie\n2.Wyjście\n");
        scanf("%d", &input);
        switch (input) {
            case 1: {
                        if (login(server_id, ID)) {
                            printf("Jesteś zalogowany\n");
                            loggedIn = 1;
                        } else {
                            printf("Zły login, lub hasło\n");
                        }
                        break;
                    }
            case 2: {
                        printf ("Wychodzę\n");
                        return;
                        break;
                    }
        }
    }
    while (loggedIn) {
        printf("Co chcesz zrobić?\n"
                "1. Przyjmij pacjenta\n"
                "2. Wyloguj i zamknij\n"
                );
        scanf("%d", &input);
        switch (input) {
            case 1: break;
            case 2: {
                        logout(server_id, ID);
                        return;
                    }
        }
    }


    return;
}

int login(int server_id, int ID) {
    return generalLogin(server_id, DOCTOR, ID);
}

int logout(int server_id, int ID) {
    return generalLogout(server_id,ID);
}

int registerUser(int server_id, int ID) {
    return 1;
}

int registeActualVisit(int server_id, int ID) {
    return 1;
}

int registerVacation(int server_id, int ID) {
    return 1;
 }
