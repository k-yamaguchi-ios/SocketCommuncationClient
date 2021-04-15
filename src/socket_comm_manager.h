#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>
#include "socket_comm_callback.h"

#define SUCCESS 0
#define FAILURE -1

class socket_comm_manager
{
public:
    socket_comm_manager();
    int connect_server( char* address, int port_number );
    int disconnect_server();
    int send_message( char* message, socket_comm_callback* callback );

private:
    int sockfd;
    bool isConnected;
    struct sockaddr_in addr;
};
