#include "patient.h" 

int connect() 
{ 
    int id = msgget(0xCAFEBABE, 0700);

    msgctl(id, IPC_RMID, NULL);
    return 1; 
}

int runInterface() {
    return 1;
}

void disconnect(){
    return;
}
