/*
 * The LUI for the movie database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
 #include "MovieDatabase.h"
 #include <stdio.h>
 #include <stdlib.h>
 /*
  * Allows the user to create a new movie entry to put
  * into the database.
  */
 int createNewEntry() {
 	// define the variables
 	char entryName[40];
 	int entryYear;
 	int rippedEntry;
 	char curr;
 	// prompt the user for the name of the movie
 	printf("%s ", "Movie Name?");
 	// read in the user's input
 	curr = getc(stdin);
 	// check the input
 	if(curr != '\n') {
 		// define the character count
 		int count = 0;
 		// parse the user's input
 		while(curr != '\n' && count < 40) {
 			entryName[count++] = curr;
 			curr = getc(stdin);
 		}
 		printf("%s", entryName)
 	} else {
 		printf("%s\n", "Please re-enter the Movie Name:");
 	}
 	return 1;
 }
 int main() {
 	// define the data members
 	MovieDatabase* database;
 	int option;
 	// initialize the database
 	database = ((MovieDatabase*) malloc(sizeof(MovieDatabase)));
 	// display welcome banner
 	printf("\n%s\n", "Welcome to the Movie Database!!! :)");
 	// load the database from the save file
 	if(loadDatabase(database)) {
 		// display the number of movies currently in the database
 		printf("%s %d %s\n\n", "There is currently a total of", database->size, "movies in the database!");
 	} else {
 		// report that the database is empty
 		printf("%s\n", "The database is currently EMPTY.");
 	}
 	// define the default option value
 	option = -1;
 	// run the interface until the user chooses to exit
 	while(option) {
	 	// display user options
	 	printf("\n%s\n", "1) Add Movie");
	 	printf("%s\n", "2) Display Database");
	 	printf("%s\n", "3) Exit the Database");
	 	printf("\n");
	 	option = getc(stdin)-48;
	 	// remove the trailing new line character
	 	getc(stdin);
	 	switch(option) {
	 		case 1: createNewEntry();break;
	 		case 2: displayDatabase(database);break;
	 		default: option = 0;break;
	 	}
	}
 	return 1;
 }