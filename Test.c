/*
 * A test file for the new code that has been added to the project.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#include "MovieDatabase.h"
#include <stdio.h>
int main() {
	MovieDatabase* database;
	MovieNode* entry;
	bool check;
	database = ((MovieDatabase*) malloc(sizeof(MovieDatabase)));
	database->size = 0;
	entry = ((MovieNode*) malloc(sizeof(MovieNode)));
	check = addEntry(entry, database);
	if(check) {
		printf("%s\n", "True");
	} else {
		printf("%s\n", "False");
	}
}