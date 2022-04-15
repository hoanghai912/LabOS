all: problem3.o factorial.o readline.o
	gcc problem3.o factorial.o readline.o -o myfactorial

problem3.o: problem3.c factorial.h readline.h
	gcc -c problem3.c

factorial.o: factorial.c factorial.h
	gcc -c factorial.c

readline.o: readline.c readline.h
	gcc -c readline.c

clean:
	rm -f *.o myfactorial