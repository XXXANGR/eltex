CFLAGS = -Werror -Wextra -Wall
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

all: clean libcontact.a program 

libcontact.a: $(OBJS)
	ar -rc libcontact.a $^
	ranlib libcontact.a
	rm -rf *.o


program: clean libcontact.a
	$(CC) $(CFLAGS) -o program -g libcontact.a -L. -lcontact
	-rm -f $(OBJS)

clean:
	-rm -rf *.o program a.out libcontact.a