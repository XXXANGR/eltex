CC = gcc

all: clean program 

program: sum max_value
	$(CC) -c src/main.c -o main.o -g
	$(CC) -c src/detect_file.c -o detect_file.o -g
	$(CC) main.o detect_file.o -o program
	-rm -f *.o

sum:
	$(CC) -c src/sum.c -o sum.o
	$(CC) sum.o -o sum
	-rm -f sum.o

max_value:
	$(CC) -c src/max_value.c -o max_value.o
	$(CC) max_value.o -o max_value
	-rm -f max_value.o

clean:
	-rm -rf *.o program a.out sum max_value

style:
	clang-format -i src/*.c