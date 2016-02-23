#include "patient.h"


int main (int argc, char *argv[])
{
    int server_message_queue_id = -1;
    int myID = -1;    

    myID = connect(&server_message_queue_id);
    
    printf("%d\n", myID);
    runInterface(server_message_queue_id, myID);


    return 0;
}
