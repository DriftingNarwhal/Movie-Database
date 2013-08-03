/*
 * The functions that will be used to manage and organize the data stored in the database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#include "MovieDatabase.h"
#include <stdlib.h>
/*
 * Adds a movie entry to the database.
 * @param entry - the entry being added
 * @param database - the movie database that the entry is being added to
 * @return true - the entry was successfully added to the database
 * @return false - the movie already exists within the database
 */
 bool addEntry(MovieNode* entry, MovieDatabase* database) {
 	// if the database is empty,
 	if((database->size) == 0) {
 		// initialize the head node to the entry
 		database->head = entry;
 		// update the size of the database
 		(database->size)++;
 		// return successful
 		return true;
 	}
 	// if not,
 	else {
 		// if the head node is equal, return false
 		if(compareEntries(database->head, entry) == 0) {
 			return false;
 		}
 		// if the head node is greater, add the entry to the front of the list
 		else if(compareEntries(database->head, entry) > 0) {
 			entry->next = database->head;
 			database->head = entry;
 			// update the size of the database
 			(database->size)++;
 			// return successful
 			return true;
 		}
 		// if the head node is less, locate the appropriate place for the entry in the database
 		else {
 			MovieNode* prev = database->head;
 			MovieNode* curr = prev->next;
	 		while(curr != NULL) {
	 			// if an entry is found that is less than, add the new entry to the database
	 			if(compareEntries(curr, entry) < 0) {
	 				prev->next = entry;
	 				entry->next = curr;
	 				// update the size of the database
	 				(database->size)++;
	 				// return sucessful
	 				return true;
	 			}
	 			// if an entry is found that is equal, return false
	 			else if(compareEntries(curr, entry) == 0) {
	 				return false;
	 			}
	 			// if an entry is found that is greater than, check the next location
	 			else {
	 				prev = curr;
	 				curr = curr->next;
	 			}
	 		}
	 		// if a location hasn't already been found, append the entry
	 		prev->next = entry;
	 		// update the size of the database
	 		(database->size)++;
	 		// return successful
	 		return true;
	 	}
 	}
 }