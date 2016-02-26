#include "doctor.h"

void runInterface(int server_id, int ID) {
    while (1){
        printf("Co chcesz robić?\n1.Logowanie\n2.Wyjście\n");
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1: {
                        if (login(server_id, ID)) {
                            printf("Jesteś zalogowany\n");
                        } else {
                            printf("Zły login, lub hasło\n");
                            continue;
                        }
                        break;
                    }
            case 2: {
                        printf ("Exiting for now\n");
                        return;
                        break;
                    }
        }
    }
    return;
}

int login(int server_id, int ID) {
    return generalLogin(server_id, DOCTOR, ID);
}

int logut(int server_id, int ID) {
    return 1;
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
