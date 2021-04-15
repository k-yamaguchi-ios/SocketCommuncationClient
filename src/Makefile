EXE = exe_client

OBJS = main.o socket_comm_manager.o io_manager.o

all: clean $(EXE)

$(EXE) : $(OBJS)
	g++ -DDEBUG -o $@ $(OBJS)

clean :
	rm -f $(EXE) $(OBJS)

