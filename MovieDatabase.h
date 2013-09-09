/*
 * Defines the database that will store the movies.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H
#include "MovieNode.h"
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
 * @param entry - the movie being added
 * @param database - the movie database that the entry is being added to
 * @return 1 - the entry was successfully added to the database
 * @return 0 - the movie already exists within the database
 */
int addEntry(Movie* entry, MovieDatabase* database);
/*
 * Compiles the database from the local save file.
 * @param database - the database to compile
 * @return 1 - the database was compiled successfully
 * @return 0 - the database failed to compile
 */
int loadDatabase(MovieDatabase* database);
/*
 * Prints the entries of the database in alphabetical order.
 * @param database - the database to print
 * @return 1 - if the database printed successfully
 * @return 0 - if the database failed to print one or more of the entries
 */
int displayDatabase(MovieDatabase* database);
/*
 * Saves the database to a local file.
 * @param database - the database to save
 * @return 1 - the database saved successfully
 * @return 0 - the database failed to save
 */
int saveDatabase(MovieDatabase* database);
#endif