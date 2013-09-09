/*
 * The functions that will be used to manage and organize the data stored in the database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#include "MovieDatabase.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * Adds a movie entry to the database.
 * @param entry - the movie being added
 * @param database - the movie database that the entry is being added to
 * @return 1 - the entry was successfully added to the database
 * @return 0 - the movie already exists within the database
 */
 int addEntry(Movie* entry, MovieDatabase* database) {
 	// if the database is empty,
 	if(!(database->size)) {
 		// initialize the head node and allocate memory
 		database->head = ((MovieNode*) malloc(sizeof(MovieNode)));
 		// configure the new head node
 		database->head->item = entry;
 		database->head->next = NULL;
 		// update the size of the database
 		(database->size)++;
 		// return successful
 		return 1;
 	}
 	// if not,
 	else {
 		// if the head node is equal, return false
 		if(!compareMovies(database->head->item, entry)) {
 			return 0;
 		}
 		// if the head node is greater, add the entry to the front of the list
 		else if(compareMovies(database->head->item, entry) > 0) {
 			// initialize the entry node
 			MovieNode* entryNode = ((MovieNode*) malloc(sizeof(MovieNode)));
 			entryNode->item = entry;
 			// place the entryNode into the database
 			entryNode->next = database->head;
 			// update the head node
 			database->head = entryNode;
 			// update the size of the database
 			(database->size)++;
 			// return successful
 			return 1;
 		}
 		// if the head node is less, locate the appropriate place for the entry in the database
 		else {
 			MovieNode* prev = database->head;
 			MovieNode* curr = prev->next;
	 		while(curr != NULL) {
	 			// if an entry is found that is equal, return false
	 			if(!compareMovies(curr->item, entry)) {
	 				return 0;
	 			}
	 			// if an entry is found that is less than, add the new entry to the database
	 			else if(compareMovies(curr->item, entry) < 0) {
	 				// initialize the entry node
	 				MovieNode* entryNode = ((MovieNode*) malloc(sizeof(MovieNode)));
	 				// configure the links around the entry node
	 				entryNode->item = entry;
	 				prev->next = entryNode;
	 				entryNode->next = curr;
	 				// update the size of the database
	 				(database->size)++;
	 				// return sucessful
	 				return 1;
	 			}
	 			// if an entry is found that is greater than, check the next location
	 			else {
	 				prev = curr;
	 				curr = curr->next;
	 			}
	 		}
	 		// initialize the entry node
	 		MovieNode* entryNode = ((MovieNode*) malloc(sizeof(MovieNode)));
	 		entryNode->item = entry;
	 		// if a location hasn't already been found, append the entry
	 		prev->next = entryNode;
	 		entryNode->next = NULL;
	 		// update the size of the database
	 		(database->size)++;
	 		// return successful
	 		return 1;
	 	}
 	}
 }
 /*
 * Compiles the database from the local save file.
 * @param database - the database to compile
 * @return 1 - the database was compiled successfully
 * @return 0 - the database failed to compile
 */
 int loadDatabase(MovieDatabase* database) {
 	// define the variables
 	FILE* saveFile;
 	char entryYear[4];
 	int rippedEntry;
 	Movie* entry;
 	char curr;
 	int count;
 	// open the file
 	saveFile = fopen("movieStorage.dat", "r");
 	// read the first character
 	curr = fgetc(saveFile);
 	if(curr != EOF) {
	 	while(curr != EOF) {
	 		// initialize the entry
		 	entry = ((Movie*) malloc(sizeof(Movie)));
		 	// initialize the entry's name
		 	entry->name = ((char*) malloc(sizeof(char)*40));
	 		// parse through each line
	 		while(curr != '\n') {
	 			// initialize the character count
	 			count = 0;
				// increment through the name in the file
		 		while(curr != ';' && curr < 40) {
		 			*((entry->name)+count++) = curr;
		 			curr = fgetc(saveFile);
		 		}
		 		// reset the count
		 		count = 0;
		 		// parse the year in the file
		 		curr = fgetc(saveFile);
		 		while(curr != ';') {
		 			entryYear[count++] = curr;
		 			curr = fgetc(saveFile);
		 		}
		 		// check if the entry has been ripped
		 		rippedEntry = fgetc(saveFile)-48;
		 		// load the next character
		 		curr = fgetc(saveFile);
		 	}
		 	// assign the variable attributes
		 	entry->year = atoi(&entryYear[0]);
		 	entry->ripped = rippedEntry;
		 	// add the entry to the database
		 	addEntry(entry, database);
		 	// load the next line
		 	curr = fgetc(saveFile);
		}
	} else {
		// return unsuccessful
		return 0;
	}
 	// read the file
 	fclose(saveFile);
 	// return successful
 	return 1;
 }
 /*
 * Prints the entries of the database in alphabetical order.
 * @param database - the database to print
 * @return 1 - if the database printed successfully
 * @return 0 - if the database failed to print one or more of the entries
 */
 int displayDatabase(MovieDatabase* database) {
 	// iterate through the database and print the information for each entry
 	if(database->size) {
 		MovieNode* curr = database->head;
 		while(curr != NULL) {
 			printf("%s (%d)\n", curr->item->name, curr->item->year);
 			curr = curr->next;
 		}
 	} else {
 		// report the error and return unsuccessful
 		printf("%s\n", "ERROR: There are currently no movies in the database.");
 		return 0;
 	}
 	// return successful
 	return 1;
 }
 /*
 * Saves the database to a local file.
 * @param database - the database to save
 * @return 1 - the database saved successfully
 * @return 0 - the database failed to save
 */
 int saveDatabase(MovieDatabase* database) {
 	// define the variables
 	MovieNode* curr;
 	FILE* saveFile;
 	// check the size of the database
 	if(database->size) {
 		// initialize the variable
 		curr = database->head;
 		// open the file
 		saveFile = fopen("movieStorage.dat", "w");
 		// append each entry to the file
 		while(curr != NULL) {
 			// grab the item
 			Movie* entry = curr->item;
 			// write its information
 			fprintf(saveFile, "%s;%i;%i\n", entry->name, entry->year, entry->ripped);
 			// move to the next entry
 			curr = curr->next;
 		}
 	} else {
 		// report the error and return unsuccessful
 		printf("%s\n", "ERROR: There are currently no movies in the database.");
 		return 0;
 	}
 	// close the file
 	fclose(saveFile);
 	// return successful
 	return 1;
 }