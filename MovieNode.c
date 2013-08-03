/*
 * The functions that are used to manage the entries in the database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#include "MovieNode.h"
/*
  * Returns a comparison of entry1 to entry2.
  * @param entry1 - the first argument of the comparison
  * @param entry2 - the second argument of the comparison
  * @return < 0 - if entry1 is less than entry2
  * @return 0 - if entry1 is equal to entry2
  * @return > 0 - if entry1 is greater than entry2
  */
 int compareEntries(MovieNode* entry1, MovieNode* entry2) {
	// return a comparison between the movies in the entries
	return compareMovies(entry1->item, entry2->item);
}