#include "lista.h"

LoggedInListElement* firstElementInList = NULL;


void addLoggedInUser(char* login, int clientID) {

    LoggedInListElement *pointer = firstElementInList;
    LoggedInListElement *newElement;

    newElement = (LoggedInListElement*)malloc(sizeof(LoggedInListElement));
    strcpy(newElement->login, login);
    newElement->clientID = clientID;
    newElement->next = NULL;

    if (pointer == NULL) {
        pointer = newElement;
    } else {
        while (pointer->next != NULL)
            pointer = pointer->next;
        pointer->next = newElement;
    }
}


LoggedInListElement* findByLogin(char* login) {
    LoggedInListElement *foundLogin = NULL;

    LoggedInListElement *pointer = firstElementInList;

    while ((pointer != NULL) &&
            (strcmp(pointer->login, login))) {
        pointer = pointer->next;
    }
    if (pointer != NULL) {
        foundLogin = pointer;
    }

    return foundLogin;
}

LoggedInListElement* findByID(int clientID) {
    LoggedInListElement *foundID = NULL;

    LoggedInListElement *pointer = firstElementInList;

    while ((pointer != NULL) &&
            (clientID == pointer->clientID)) {
        pointer = pointer->next;
    }
    if (pointer != NULL) {
        foundID = pointer;
    }

    return foundID;
}

int deleteByLogin(char* login) {
    LoggedInListElement* pointer = firstElementInList;

    if (pointer == NULL) {
        return 0;
    } else if (!strcmp(pointer->login, login)) {
        firstElementInList = pointer->next;
        free(pointer);
    } else {
        while ((pointer->next != NULL) &&
                (strcmp(pointer->next->login, login))) {
            pointer = pointer->next;
        }
        if (pointer->next != NULL) {
            LoggedInListElement* toDelete = pointer->next;
            pointer->next = pointer->next->next;
            free(toDelete);
        } else {
            return 0;
        }
    }

    return 1;
}

int deleteByClientID(int clientID) {
    LoggedInListElement* pointer = firstElementInList;

    if (pointer == NULL) {
        return 0;
    } else if (pointer->clientID == clientID) {
        firstElementInList = pointer->next;
        free(pointer);
    } else {
        while ((pointer->next != NULL) &&
                !(pointer->next->clientID == clientID)) {
            pointer = pointer->next;
        }
        if (pointer->next != NULL) {
            LoggedInListElement* toDelete = pointer->next;
            pointer->next = pointer->next->next;
            free(toDelete);
        } else {
            return 0;
        }
    }

    return 1;
}

void recDeleteAllElementsInList(LoggedInListElement* first) {
    if (first != NULL) {
        recDeleteAllElementsInList(first->next);
        free(first);
    }
}

void deletAllElementsInList() {
    recDeleteAllElementsInList(firstElementInList);
    return;
}
