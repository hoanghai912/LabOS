all: problem2.o readline.o
	gcc problem2.o readline.o -o prob2

problem1.o: problem2.c readline.h
	gcc -c problem2.c

readline.o: readline.c readline.h
	gcc -c readline.c

clean:
	rm -f *.o prob2