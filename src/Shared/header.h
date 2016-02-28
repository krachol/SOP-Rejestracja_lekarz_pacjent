#ifndef HEADER_H_9HNW3YFM
#define HEADER_H_9HNW3YFM

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "messages.h"

typedef struct _date {
    int minutes;
    int hour;
    int day;
    int month;
    int year;
} Date;

typedef struct _visit {
    char doctor_login[LOGIN_SIZE];
    char patient_login[LOGIN_SIZE];
    Date date;
} Visit;

#endif /* end of include guard: HEADER_H_9HNW3YFM */
