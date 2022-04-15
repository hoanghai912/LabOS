all: problem1.o factorial.o
	gcc problem1.o factorial.o -o prob1

problem1.o: problem1.c factorial.h
	gcc -c problem1.c

factorial.o: factorial.c factorial.h
	gcc -c factorial.c

clean:
	rm -f *.o prob1