CC = gcc
CFLAGS = -g -Wall

default: Test

Test: Test.o MovieDatabase.o MovieNode.o Movie.o
	$(CC) $(CFLAGS) -o Test Test.o MovieDatabase.o MovieNode.o Movie.o

Test.o: MovieDatabase.o Test.c 
	$(CC) $(CFLAGS) -c Test.c

MovieDatabase.o: MovieNode.o MovieDatabase.c MovieDatabase.h
	$(CC) $(CFLAGS) -c MovieDatabase.c 

MovieNode.o: Movie.o MovieNode.c MovieNode.c 
	$(CC) $(CFLAGS) -c MovieNode.c 

Movie.o: Movie.c Movie.h
	$(CC) $(CFLAGS) -c Movie.c 

clean:
	$(RM) Test *.o *~
	