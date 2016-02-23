#ifndef PATIENT_H_J0NSD3QQ
#define PATIENT_H_J0NSD3QQ

#include "client.h"

int runInterface(int server_id, int ID);

int login(int server_id, int myID);
void logout(int server_id, int myID);
void registerVisit(int server_id, int myID);
void getDoctorListForCurrentDay(int server_id, int myID);
void getAvailableVisitsForCurrentDay(int server_id, int myID);
void getVisitStatus(int server_id, int myID);
void cancelVisit(int server_id, int myID);
void getFailedLoginsNumber(int server_id, int myID);

#endif /* end of include guard: PATIENT_H_J0NSD3QQ */
