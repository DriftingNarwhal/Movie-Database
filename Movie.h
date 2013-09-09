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
typedef struct Movie {
	char* name;
	int year;
	int ripped;
} Movie;
/*
 * Returns a comparison of the first movie to the second movie.
 * @param movie1 - the first argument of the comparison
 * @param movie2 - the second argument of the comparison
 * @return < 0 - if movie1 is less than movie2
 * @return 0 - if movie1 is equal to movie2
 * @return > 0 - if movie1 is greater than movie2
 */
int compareMovies(Movie* movie1, Movie* movie2);
#endif