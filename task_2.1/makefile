CC = gcc
CFLAGS = -Wall -Wextra -Werror

my_program: main.o add_contact.o edit_contact.o show_list_contacts.o choice.o delete_contact.o find_people.o
	$(CC) main.o add_contact.o edit_contact.o show_list_contacts.o choice.o delete_contact.o find_people.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

add_contact.o: add_contact.c
	$(CC) $(CFLAGS) -c add_contact.c -o add_contact.o

edit_contact.o: edit_contact.c
	$(CC) $(CFLAGS) -c edit_contact.c -o edit_contact.o

show_list_contacts.o: show_list_contacts.c
	$(CC) $(CFLAGS) -c show_list_contacts.c -o show_list_contacts.o

choice.o: choice.c
	$(CC)  $(CFLAGS) -c choice.c -o choice.o

delete_contact.o: delete_contact.c
	$(CC) $(CFLAGS) -c delete_contact.c -o delete_contact.o

find_people.o: find_people.c
	$(CC) $(CFLAGS) -c find_people.c -o find_people.o

clean:
	rm -f *.o my_program
