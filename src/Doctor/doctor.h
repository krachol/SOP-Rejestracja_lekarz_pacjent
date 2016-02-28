#ifndef DOCTOR_H_2UXHCEZE
#define DOCTOR_H_2UXHCEZE

#include "client.h"

void runInterface(int server_id, int ID);

int login(int server_id, int ID);
int logout(int server_id, int ID);
int registerUser(int server_id, int ID);

int registeActualVisit(int server_id, int ID);
int registerVacation(int server_id, int ID);

#endif /* end of include guard: DOCTOR_H_2UXHCEZE */
