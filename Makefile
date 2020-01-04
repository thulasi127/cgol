all: CGOL

CGOL: CGOL.o
			gcc -ansi -Wall -o CGOL CGOL.o

CGOL.o: CGOL.c
				gcc -ansi -Wall -c CGOL.c

clean:
			rm CGOL.o
