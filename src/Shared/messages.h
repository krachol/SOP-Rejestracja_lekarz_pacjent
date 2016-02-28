#ifndef MESSAGES_H_8YZU3XLV
#define MESSAGES_H_8YZU3XLV

#include "message_types.h"
#include <time.h>

#define MESSAGE_SIZE 512
#define LOGIN_SIZE 50
#define NAME_SIZE 50
#define PESEL_SIZE 11
#define PASSWORD_SIZE 50

typedef struct msgbuf {
    long type;
    long clientID;
    
    char message[MESSAGE_SIZE];
} BaseMessage;

/* MESSAGES */

typedef struct _current_time_message {
    long type;
    struct tm time;
} CurrentTimeMessage;

typedef struct _get_time_message {
    long type;
    int ID;
} GetTimeMessage;

typedef struct _login_info_message {
    long type;
    int status;
} LoginInfoMessage;

typedef struct _connect_info_message{
    long type;
    int number;
} ConnectInfoMessage;

typedef struct _connect_message{
    long type;
} ConnectMessage;

typedef struct _login_message{
    long type;
    int sender;
    int ID;
    char login[LOGIN_SIZE];
    char password[PASSWORD_SIZE];
} LoginMessage;

typedef struct _logout_message {
   long type;
   int ID;
} LogoutMessage;

typedef struct _register_visit_message {
    long type;
    int ID;
    int sender;
    char name[NAME_SIZE];
    char surname[NAME_SIZE];
    char PESEL[PESEL_SIZE];
    struct tm timeanddate; 
} RegisterVisitMessage;


typedef union _message {
    BaseMessage base_message;
    LoginMessage login_message;
    LogoutMessage logout_message;
    ConnectMessage connect_message;
    ConnectInfoMessage connect_info_message;
    RegisterVisitMessage register_visit_mesage;
    LoginInfoMessage login_info_message;
    GetTimeMessage get_time_message;
    CurrentTimeMessage current_time_message;
} Message;


#endif /* end of include guard: MESSAGES_H_8YZU3XLV */
