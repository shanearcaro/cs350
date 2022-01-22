OBJS = reality.c reality4.c
CC = gcc
PROGS = reality reality4

all: $(PROGS)

reality: reality.o
	$(CC) reality.c -o reality
reality4: reality4.o
	$(CC) reality4.c -o reality4
clean:
	rm *.o reality reality4

