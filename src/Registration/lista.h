#ifndef LISTA_H_SJEAOYUF
#define LISTA_H_SJEAOYUF

#define LOGIN_SIZE 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _logged_in_list_element {
    char login[LOGIN_SIZE];
    int clientID;
    struct _logged_in_list_element *next;
} LoggedInListElement;


void addLoggedInUser(char* login, int clientID) ;
LoggedInListElement* findByLogin(char* login) ;
LoggedInListElement* findByID(int clientID) ;
int deleteByLogin(char* login);
int deleteByClientID(int clientID);
void deletAllElementsInList();


#endif /* end of include guard: LISTA_H_SJEAOYUF */
