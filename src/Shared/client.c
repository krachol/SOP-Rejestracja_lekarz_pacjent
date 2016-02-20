#include "client.h"

//Establish connection
int connect(int* id) { 

    while (-1 == (*id = msgget(0xCAFEBABE, 0700))) {
        printf("Haven't been able to connect. Trying again in 1 second\n");
        sleep(1);
    }

    return 1;
}
