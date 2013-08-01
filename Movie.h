/*
 * Defines the movie structure that will be stored in the database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#ifndef MOVIE_H
#define MOVIE_H
/*
  * The movie struct.
  * @var name - the name of the movie
  * @var year - the year the movie was released
  */
typedef struct movie {
	char* name;
	int year;
};
#endif