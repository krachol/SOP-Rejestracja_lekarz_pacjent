#ifndef PATIENT_H_J0NSD3QQ
#define PATIENT_H_J0NSD3QQ

#include "client.h"

int runInterface();

void login();
void logout();
void registerVisit();
void getDoctorListForCurrentDay();
void getAvailableVisitsForCurrentDay();
void getVisitStatus();
void cancelVisit();
void getFailedLoginsNumber();

#endif /* end of include guard: PATIENT_H_J0NSD3QQ */
