#include "doctor.h"

int main (int argc, char *argv[])
{
    int server_message_queue_id = -1;

    int id = connect(&server_message_queue_id);

    runInterface(server_message_queue_id, id);

    return 0;
}

