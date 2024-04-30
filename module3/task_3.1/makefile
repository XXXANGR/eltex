CFLAGS = -Werror -Wextra -Wall
CC = gcc
SRC = src/
all: receiver sender

receiver:
	$(CC) -c $(SRC)receiver.c $(SRC)received_message.c 
	$(CC) receiver.o received_message.o -o receiver
	rm -rf receiver.o received_message.o

sender:
	$(CC) -c $(SRC)sender.c $(SRC)/create_sender.c $(SRC)/send_sender.c
	$(CC) sender.o create_sender.o send_sender.o -o sender
	rm -rf sender.o create_sender.o send_sender.o

clean:
	-rm -rf *.o program sender a.out receiver msg_queue
