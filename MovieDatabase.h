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
 * @var numMovies - the total number of movies currently in the database
 */
typedef struct movieDatabase {
	movieNode* head;
	int numMovies;
};
#endif