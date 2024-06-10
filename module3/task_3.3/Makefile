CFLAGS = -Werror -Wextra -Wall
CC = gcc
SRC = src/
all: client server

client:
	$(CC) -c $(SRC)client.c $(SRC)client_func.c 
	$(CC) client.o client_func.o -o client
	rm -rf client.o client_func.o

server:
	$(CC) -c $(SRC)server.c $(SRC)server_func.c 
	$(CC) server.o server_func.o -o server
	rm -rf server.o server_func.o 

clean:
	-rm -rf *.o program server a.out client msg_queue 
