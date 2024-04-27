CFLAGS = -Werror -Wextra -Wall
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -g

clean:
	-rm -rf *.o program a.out