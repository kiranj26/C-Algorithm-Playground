CC=gcc
CFLAGS=-I.

all: sorting/simple_sort

sorting/simple_sort: sorting/simple_sort.o
	$(CC) -o sorting/simple_sort sorting/simple_sort.o

sorting/simple_sort.o: sorting/simple_sort.c
	$(CC) -c sorting/simple_sort.c $(CFLAGS)

clean:
	rm -f sorting/*.o sorting/simple_sort
