#include <stdio.h>
#include <iostream>
#include "io_manager.h"
#include "socket_comm_manager.h"


int main(){

    io_manager im;
    im.client_main();

    return 0;
}
