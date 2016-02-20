//A simple program that calculates square root of number
#include "patient.h"
#include "header.h"

int main (int argc, char *argv[])
{
    int server_message_queue_id = -1;
    
    connect(&server_message_queue_id);
    
    runInterface();

    return 0;
}
