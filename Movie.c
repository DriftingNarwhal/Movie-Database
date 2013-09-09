/*
 * The necessary functions for handling the movies in the database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#include "Movie.h"
#include <string.h>
/*
 * Returns a comparison of the first movie to the second movie.
 * @param movie1 - the first argument of the comparison
 * @param movie2 - the second argument of the comparison
 * @return < 0 - if movie1 is less than movie2
 * @return 0 - if movie1 is equal to movie2
 * @return > 0 - if movie1 is greater than movie2
 */
int compareMovies(struct Movie* movie1, struct Movie* movie2) {
	// compare the names of the movies
	int comparison = strcmp(movie1->name, movie2->name);
	// check the value of the comparison
	if(!comparison) {
		// return a comparison between the years of the movies
		return (movie1->year) - (movie2->year);
	}
	// else, return the comparison
	return comparison;
}