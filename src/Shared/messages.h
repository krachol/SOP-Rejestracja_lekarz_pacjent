#ifndef MESSAGES_H_8YZU3XLV
#define MESSAGES_H_8YZU3XLV

#include "message_types.h"

#define MESSAGE_SIZE 512
#define LOGIN_SIZE 50
#define PASSWORD_SIZE 50

typedef struct msgbuf {
    long type;
    long clientIS;
    
    char message[MESSAGE_SIZE];
} BaseMessage;

/* MESSAGES */

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
   int sender;
   int number;
   char login[LOGIN_SIZE];
} LogoutMessage;

typedef union _message {
    BaseMessage base_message;
    LoginMessage login_message;
    LogoutMessage logout_message;
    ConnectMessage connect_message;
    ConnectInfoMessage connect_info_message;
    LoginInfoMessage login_info_message;
} Message;


#endif /* end of include guard: MESSAGES_H_8YZU3XLV */
