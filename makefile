CC=gcc 
CFLAGS=-Wall -std=c99 -pedantic

output: a4q1.o
	$(CC) $(CFLAGS) a4q1.o -o output
a4q1.o: a4q1.c header.h 
	$(CC) $(CFLAGS) -c a4q1.c
clean:
	rm *.o output