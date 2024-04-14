CFLAGS = -Werror -Wextra -Wall
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

all: clean libcontact.so program 

libcontact.so: $(OBJS)
	$(CC) -shared -o libcontact.so $(OBJS)

program: libcontact.so
	$(CC) $(CFLAGS) -o program -g libcontact.so -L. -lcontact
	-rm -f $(OBJS)

clean:
	-rm -rf *.o program a.out libcontact.so
