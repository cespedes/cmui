CC	=	gcc
CFLAGS	=	-O2 -g -Wall

OBJ	=	main.o frontend.o help.o dumb.o

all:	mui

mui:	$(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) mui *.o
