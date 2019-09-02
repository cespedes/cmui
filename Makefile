CC	=	gcc
CFLAGS	=	-O2 -g -Wall

OBJ	=	main.o cmd.o help.o

all:	mui

mui:	$(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) mui *.o
