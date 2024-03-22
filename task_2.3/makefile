CC = gcc
CFLAGS = -Wall -Wextra -Werror

my_program: main.o multiplication.o subtraction.o addition.o division.o	choice_operation.o	
	$(CC) main.o multiplication.o subtraction.o addition.o division.o	choice_operation.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

choice_operation.o: choice_operation.c
	$(CC) $(CFLAGS) -c choice_operation.c -o choice_operation.o	

addition.o: addition.c
	$(CC) $(CFLAGS) -c addition.c -o addition.o

division.o: division.c
	$(CC) $(CFLAGS) -c division.c -o division.o	

subtraction.o: subtraction.c
	$(CC) $(CFLAGS) -c subtraction.c -o subtraction.o

multiplication.o: multiplication.c
		$(CC) $(CFLAGS) -c multiplication.c -o multiplication.o

clean:
	rm -f *.o my_program