EXE = exe_client

OBJS = main.o socket_comm_manager.o io_manager.o

all: clean $(EXE)

$(EXE) : $(OBJS)
	g++ -o $@ $(OBJS)

%.o : %.c
	g++ -c -o $@ $<

clean :
	rm -f $(EXE) $(OBJS)
