CFLAGS = -Werror -Wextra -Wall
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

all: clean program 

program: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -g
	-rm -f $(OBJS)

clean:
	-rm -rf *.o program a.out