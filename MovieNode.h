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
 typedef struct movieNode {
 	movie* item;
 	struct movieNode* next;
 };
 #endif