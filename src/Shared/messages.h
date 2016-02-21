#ifndef MESSAGES_H_8YZU3XLV
#define MESSAGES_H_8YZU3XLV

#include "message_types.h"

#define MESSAGE_SIZE 512
#define LOGIN_SIZE 50
#define PASSWORD_SIZE 50

typedef struct msgbuf {
    long type;
    char message[MESSAGE_SIZE];
} BaseMessage;

/* MESSAGES */

typedef struct _login_message{
    long type;
    int sender;
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
} Message;

#endif /* end of include guard: MESSAGES_H_8YZU3XLV */
