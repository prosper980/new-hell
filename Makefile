CC := gcc
CFLAGS := -Wall -g
OBJ := $(wildcard *.o) 



all: $(OBJ)
	$(CC) $^ -o new-shell

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

multipipe.o: multipipe.c multipipe.h
	$(CC) $(CFLAGS) -c multipipe.c

readinput.o: readinput.c readinput.h
	$(CC) $(CFLAGS) -c readinput.c

execline.o: execline.c execline.h
	$(CC) $(CFLAGS) -c execline.c

builtin.o: builtin.c builtin.h
	$(CC) $(CFLAGS) -c builtin.c

parseline.o: parseline.c parseline.h
	$(CC) $(CFLAGS) -c parseline.c

execpipe.o: execpipe.c execpipe.h
		$(CC) $(CFLAGS) -c execpipe.c

parsepipe.o: parsepipe.c parsepipe.h
	$(CC) $(CFLAGS) -c parsepipe.c






clean:
	rm *.o