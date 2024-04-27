CFLAGS = -Werror -Wextra -Wall
CC = gcc
SRC = src/
all: writer reader

writer:
	$(CC) -c $(SRC)writer.c -o writer.o
	$(CC) writer.o -o writer
	rm -rf writer.o

reader:
	$(CC) -c $(SRC)reader.c -o reader.o
	$(CC) reader.o -o reader
	rm -rf reader.o
clean:
	-rm -rf *.o program a.out my_fifo reader writer
