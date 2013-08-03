/*
 * Defines the node that will be used to store the movies in the database.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#ifndef MOVIENODE_H
#define MOVIENODE_H
#include "Movie.h"
/*
 * The node struct that will be used to store the movies.
 * @var item - the movie contained in the node
 * @var next - the next movie in the database
 */
 typedef struct MovieNode {
 	Movie* item;
 	struct MovieNode* next;
 } MovieNode;
 /*
  * Returns a comparison of entry1 to entry2.
  * @param entry1 - the first argument of the comparison
  * @param entry2 - the second argument of the comparison
  * @return < 0 - if entry1 is less than entry2
  * @return 0 - if entry1 is equal to entry2
  * @return > 0 - if entry1 is greater than entry2
  */
 int compareEntries(MovieNode* entry1, MovieNode* entry2);
 #endif