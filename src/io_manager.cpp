#include "io_manager.h"

bool io_manager::is_received = false;
char io_manager::sql_result[500];

void io_manager::my_callback::on_receive( char* message ) {
    is_received = true;
    cout << "on receive" << endl;
    strcpy(sql_result, message); 
}

void io_manager::client_main(){

    socket_comm_manager manager; //インスタンス生成
    my_callback callback; //オブジェクト型
    int result; //関数の結果
    bool is_connect = false;
    char buf[200];

    cout << CHAR_SEVER_CONNECT << endl;

    /* ソケット接続*/
    for ( int i = 0; i < 5; i++ ) {
        result = manager.connect_server(ADDRESS,PORT_NUMBER);
        if(result == 0) {
            is_connect = true;
            break;
        }
    }

    if ( !is_connect ) {
        cout << CHAR_SEVER_FAIL_CONNECT << endl;
        return;
    }

    while (1) {
        
        memset(sql_result, 0x00, sizeof(sql_result));
        memset(buf, 0x00, sizeof(buf));

        cout << CHAR_SQL_INPUT << endl;

        cin >> buf;

        if (strcmp(buf, "exit") == 0) {
            cout << CHAR_SYSTEM_END << endl;
            break;
        } else if (strcmp(buf, "") == 0) {
            cout << CHAR_FAIL_INPUT << endl;
        } else {
            for ( int i = 0; i < 5; i++ ) {
                result = manager.send_message(buf, &callback);

                if ( result == 0 ) {
                    break;
                }
            }

            if ( result != 0 ) {
                cout << CHAR_SQL_FAIL_SEND << endl;
            } else {
                for ( int i = 0; i < 1800; i++ ) {
                    if( is_received ) {
                        cout << sql_result << endl;
                        break;
                    } else {
                        cout << "wait receive" << endl;
                        usleep(100*1000);
                    }
                }
                if ( !is_received ) {
                    cout << CHAR_SEVER_TIMEOUT << endl;
                }
            }
        }
    }
    return;
}
