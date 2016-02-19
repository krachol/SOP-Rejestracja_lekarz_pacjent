//A simple program that calculates square root of number
#include "patient.h"
#include "header.h"

int main (int argc, char *argv[])
{
    while (!connect()) {
        printf("Haven't been able to connect. Trying again in 1 second\n");
        sleep(1);
    }

    runInterface();

    disconnect();

    return 0;
}
