#ifndef PATIENT_H_J0NSD3QQ
#define PATIENT_H_J0NSD3QQ

#include "client.h"

int runInterface(int server_id, int ID);

void login(int server_id, int myID);
void logout();
void registerVisit();
void getDoctorListForCurrentDay();
void getAvailableVisitsForCurrentDay();
void getVisitStatus();
void cancelVisit();
void getFailedLoginsNumber();

#endif /* end of include guard: PATIENT_H_J0NSD3QQ */
