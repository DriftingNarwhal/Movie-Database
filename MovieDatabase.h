/*
 * Defines the database that will store the movies.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H
#include "MovieNode.h"
#include <stdbool.h>
/*
 * The database structure to store the movies.
 * @var head - the first movie in the database
 * @var size - the total number of movies currently in the database
 */
typedef struct MovieDatabase {
	MovieNode* head;
	int size;
} MovieDatabase;
/*
 * Adds a movie entry to the database.
 * @param entry - the entry being added
 * @param database - the movie database that the entry is being added to
 * @return true - the entry was successfully added to the database
 * @return false - the movie already exists within the database
 */
bool addEntry(MovieNode* entry, MovieDatabase* database);
#endif