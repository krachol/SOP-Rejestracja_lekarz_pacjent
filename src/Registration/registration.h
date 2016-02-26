#ifndef REGISTRATION_H_WL6HU8XK
#define REGISTRATION_H_WL6HU8XK

#include "header.h"
#include "lista.h"

void registrationSendMessage(int server_id, int clientID, Message message);
void checkConnectionRequests(int server_id, int* clientCounter);

void login(int server_id);
void logout(int server_id);
void registerUser(int server_id);

void registerVisit(int server_id);
void sendDoctorListForCurrentDay(int server_id);
void sendAvailableVisitsForCurrentDay(int server_id);
void sendVisitStatus(int server_id);
void cancelVisit(int server_id);
void sendInfoAboutLoginTries(int server_id);

void registeActualVisit(int server_id);
void registerVacation(int server_id);


#endif /* end of include guard: REGISTRATION_H_WL6HU8XK */
