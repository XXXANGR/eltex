#CFLAGS = -Werror -Wextra -Wall
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -g
	-rm -f $(OBJS)

clean:
	-rm -rf *.o program a.out numbers.txt