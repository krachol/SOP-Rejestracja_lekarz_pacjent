//A simple program that calculates square root of number
#include "patient.h"
#include "header.h"

int main (int argc, char *argv[])
{
    int server_message_queue_id = 0;
    while (!connect(&server_message_queue_id)) {
        printf("Haven't been able to connect. Trying again in 1 second\n");
        sleep(1);
    }

    runInterface();

    disconnect(&server_message_queue_id);

    return 0;
}
