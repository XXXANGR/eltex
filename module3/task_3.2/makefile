CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/



all: first_user second_user

first_user: 
	$(CC) -c $(SRC)first_create.c $(SRC)first_get_key.c $(SRC)first_connect_message.c $(SRC)first_send_message.c $(SRC)first_receive_message.c $(SRC)first_user.c $(SRC)first_delete_message.c
	$(CC) first_create.o first_get_key.o first_connect_message.o first_send_message.o first_receive_message.o first_user.o first_delete_message.o -o first_user
	rm -rf *.o

second_user: 
	$(CC) -c $(SRC)second_get_key.c $(SRC)second_connect_message.c $(SRC)second_send_message.c $(SRC)second_receive_message.c $(SRC)second_user.c
	$(CC) second_get_key.o second_connect_message.o second_send_message.o second_receive_message.o second_user.o -o second_user
	rm -rf *.o

clean:
	-rm -rf first_user second_user msg_queue
