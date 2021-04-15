class socket_comm_callback {
public:
    virtual void on_receive( char* message ) = 0;
};
