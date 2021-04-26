#include <stdio.h>
#include <iostream>
#include "socket_comm_manager.h"

#define ADDRESS "127.0.0.1"
#define PORT_NUMBER 8765
#define SOCKET_MAX_LOOP 5
#define MESSAGE_SEND_MAX_LOOP 5
#define SQL_RESULT_MAX_LOOP 1800
#define SECOND_SLEEP 100000 
#define CHAR_SEVER_CONNECT "サーバーに接続します"
#define CHAR_SEVER_FAIL_CONNECT "サーバーへの接続が失敗しました"
#define CHAR_SQL_INPUT "実行するSQLを入力してください\n終了する場合は\"exit\"と入力してください"
#define CHAR_SYSTEM_END "システムを終了します"
#define CHAR_FAIL_INPUT "何も入力されていません"
#define CHAR_SQL_FAIL_SEND "SQLの送信に失敗しました"
#define CHAR_SEVER_TIMEOUT "サーバーへのリクエストがタイムアウトしました"


using namespace std;

class io_manager {
    class my_callback : public socket_comm_callback {
        public:
            void on_receive( char* message );
    };
    public:
    void client_main();
    private:
    static bool is_received;
    static char sql_result[500];

};

