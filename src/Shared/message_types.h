#ifndef MESSAGE_TYPES_H_SHK74CN3
#define MESSAGE_TYPES_H_SHK74CN3

#define OK 0
#define NOT_OK 1

/* Senders */
#define DOCTOR 0
#define PATIENT 1
#define REGISTRATION 2

/* Message types */
#define DISCONNECT_CLIENT_TO_REG_MSG 28
#define CONNECT_CLIENT_TO_REG_MSG 29
#define GET_TIME_CLIENT_TO_REG_MSG 30
#define LOGIN_CLIENT_TO_REG_MSG 2
#define LOGOUT_CLIENT_TO_REG_MSG 3
#define REGISTER_CLIENT_TO_REG_MSG 1
#define REGISTER_VISIT_CLIENT_TO_REG_MSG 4

#define SEND_ME_DOCTORS_LIST_AT_DATE_PAT_TO_REG_MSG 5
#define SEND_ME_AVAILABLE_VISITS_AT_DATE_PAT_TO_REG_MSG 6
#define CHANGE_VISIT_DATE_PAT_TO_REG_MSG 7
#define CANCEL_VIST_PAT_TO_REG_MSG 7
#define HOW_MANY_FAILED_LOGINS_PAT_TO_REG_MSG 8

#define LOGIN_INFO_REG_TO_PAT_MSG 9
#define CONNECT_INFO_REG_TO_CLIENT_MSG 30
#define LOGOUT_REG_TO_PAT_MSG 10
#define REGISTER_VISIT_INFO_REG_TO_PAT_MSG 11
#define REGISTER_USER_INFO_REG_TO_PAT_MSG 12
#define DOCTORS_LIST_AT_DATE_REG_TO_PAT_MSG 13
#define VISTS_LIST_AT_DATE_REG_TO_PAT_MSG 14
#define VISIT_STATUS_REG_TO_PAT_MSG 15
#define VISIT_CANCEL_INFO_REG_TO_PAT_MSG 16
#define FAILED_LOGINS_INFO_REG_TO_PAT_MSG 17

#define TAKING_A_VACATION_DOC_TO_REG_MSG 22

#define LOGIN_INFO_REG_TO_DOC_MSG 23
#define REGISTER_INFO_REG_TO_DOC_MSG 24
#define VISIT_REGISTERED_REG_TO_DOC_MSG 25
#define VACATION_REGISTERED_REG_TO_DOC_MSG 26
#define LOGOUT_REG_TO_DOC_MSG 27

#endif /* end of include guard: MESSAGE_TYPES_H_SHK74CN3 */
