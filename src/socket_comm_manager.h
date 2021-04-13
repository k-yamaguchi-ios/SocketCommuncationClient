#include "socket_comm_callback.h"

class socket_comm_manager
{
public:
    int connect( char* address, int port_number );
    int disconnect();
    int send_message( char* message, socket_comm_callback* callback );
};
