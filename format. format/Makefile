COMPILER = gcc
CCFLAGS = -ansi -pedantic -Wall

format: format.h format.c
	$(COMPILER) $(CCFLAGS) -o format format.c

clean:
	rm -f format
	rm -f *.o
