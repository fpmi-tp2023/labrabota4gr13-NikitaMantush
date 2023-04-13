CC = gcc
CFLAGS = -Wall

all: main

main: main.o m_server.o
 $(CC) $(CFLAGS) -o main main.o m_server.o

main.o: main.c m_interface.h
 $(CC) $(CFLAGS) -c main.c

m_server.o: m_server.c m_interface.h
 $(CC) $(CFLAGS) -c m_server.c

clean:
	rm -f main *.o
