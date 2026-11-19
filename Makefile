# Makefile for MPI/OpenMP Hello World program
#
# Jim Teresco, CSIS 335, Siena University
# Fall 2026
#
CFILES=mpiopenmp-hello.c
OFILES=$(CFILES:.c=.o)
CC=mpicc
CFLAGS=-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include
LDFLAGS=-L/opt/homebrew/opt/libomp/lib -lomp

mpiopenmp-hello:	$(OFILES)
	$(CC) -o mpiopenmp-hello $(OFILES) $(LDFLAGS)

clean::
	/bin/rm -f mpiopenmp-hello $(OFILES)
