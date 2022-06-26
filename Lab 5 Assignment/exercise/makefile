all: clean install
	./program

install: program

clean: 
	rm -rf *.o program

program: linkedlist.o main.o
	gcc -o program linkedlist.o main.o

main.o:
	gcc -c main.c

linkedlist.o:
	gcc -c linkedlist.c



