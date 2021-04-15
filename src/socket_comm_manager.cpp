#include "socket_comm_manager.h"

void send_thread( int sockfd, char* &message, socket_comm_callback* &callback );

using namespace std;

socket_comm_manager::socket_comm_manager() {
    sockfd = 0;
    isConnected = false;
    memset(&addr, 0, sizeof(struct sockaddr_in));
}

int socket_comm_manager::connect_server( char* address, int port_number ) {
    int result = FAILURE;

    sockfd = socket( AF_INET, SOCK_STREAM, 0 );
    //アドレスの生成
    addr.sin_family = AF_INET; //アドレスファミリ(ipv4)
    addr.sin_port = htons( port_number ); //16bitホストバイトオーダーをネットワークバイトオーダーに変換
    addr.sin_addr.s_addr = inet_addr( address ); //inet_addr()関数はアドレスの翻訳

    //ソケット接続要求
    result = connect(sockfd, (struct sockaddr *)&addr, (long unsigned int)sizeof(struct sockaddr_in));
    if ( result == SUCCESS ) {
        isConnected = true;
    }
    return result;
}

int socket_comm_manager::disconnect_server() {
    if ( isConnected ) {
        return FAILURE;
    }
    return close( sockfd );
}

int socket_comm_manager::send_message( char* message, socket_comm_callback* callback ) {
    if ( isConnected ) {
        thread t( send_thread, sockfd, ref( message ), ref( callback ) );
        t.detach();
    }
    return 0;
}

void send_thread( int sockfd, char* &message, socket_comm_callback* &callback ) {
    char s_buf[100];
    char r_buf[100];
    int result;
    memset( r_buf, 0x00, sizeof( r_buf ) );
    memset( s_buf, 0x00, sizeof( r_buf ) );
    strncpy( s_buf, message, strlen(message) );
    strcat( s_buf, "\n" );
    while (1) {
        result = write( sockfd, s_buf, sizeof( s_buf ) );
        if ( result > 0 ) {
            break;
        }
        usleep( 500 * 1000 );
    }
    recv( sockfd, r_buf, sizeof( r_buf ), 0 );
    if ( strlen( r_buf ) < 1 ) {
        strcpy( r_buf, "Query Failed. :(" );
    }

    callback->on_receive( r_buf );
}
