#ifndef CLIENT_H_5KYS27RS
#define CLIENT_H_5KYS27RS

#include "header.h"


//Establish connection
int connect(int * id);
int generalLogin (int server_id, int sender, int ID);
int generalLogout (int server_id, int ID);


void sendMessage(int server_id, Message message);
Message receiveMessage(int server_id, long type);

#endif /* end of include guard: CLIENT_H_5KYS27RS */
