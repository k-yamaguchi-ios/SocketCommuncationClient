EXE = exe_client

OBJS = main.o socket_comm_manager.o io_manager.o
SRCS = main.cpp socket_comm_manager.cpp io_manager.cpp

all: clean $(EXE)

$(EXE) : $(OBJS)
	g++ -o $@ $(OBJS)
.cpp.o :
	g++ -c $<

clean :
	rm -f $(EXE) $(OBJS)

