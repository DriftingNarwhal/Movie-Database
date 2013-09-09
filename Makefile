CC = gcc
CFLAGS = -g -Wall

default: MovieDB

MovieDB: MovieDB.o MovieDatabase.o MovieNode.o Movie.o
	$(CC) $(CFLAGS) -o MovieDB MovieDB.o MovieDatabase.o MovieNode.o Movie.o

MovieDB.o: MovieDatabase.o MovieDB.c 
	$(CC) $(CFLAGS) -c MovieDB.c

MovieDatabase.o: MovieNode.o MovieDatabase.c MovieDatabase.h
	$(CC) $(CFLAGS) -c MovieDatabase.c 

MovieNode.o: Movie.o MovieNode.c MovieNode.c 
	$(CC) $(CFLAGS) -c MovieNode.c 

Movie.o: Movie.c Movie.h
	$(CC) $(CFLAGS) -c Movie.c 

clean:
	$(RM) Test *.o *~
	