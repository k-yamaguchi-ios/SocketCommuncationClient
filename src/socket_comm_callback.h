class socket_comm_callback {
public:
    virtual on_receive( char* message ) = 0;
};
