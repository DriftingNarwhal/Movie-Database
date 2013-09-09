/*
 * A test file for the new code that has been added to the project.
 * @author Ian Riley <ian-riley@utulsa.edu>
 */
#include "MovieDatabase.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	MovieDatabase* database;
	MovieDatabase* database2;
	Movie* entry1;
	Movie* entry2;
	Movie* entry3;
	char* name1 = "Iron Man";
	char* name2 = "Thor 2";
	char* name3 = "Captain America";
	int year1 = 2010;
	int year2 = 2013;
	int year3 = 2011;
	int check;
	database = ((MovieDatabase*) malloc(sizeof(MovieDatabase)));
	database->size = 0;
	entry1 = ((Movie*) malloc(sizeof(Movie)));
	entry1->name = name1;
	entry1->year = year1;
	entry2 = ((Movie*) malloc(sizeof(Movie)));
	entry2->name = name2;
	entry2->year = year2;
	entry3 = ((Movie*) malloc(sizeof(Movie)));
	entry3->name = name3;
	entry3->year = year3;
	check = addEntry(entry1, database);
	check = addEntry(entry2, database);
	check = addEntry(entry3, database);
	if(check) {
		printf("%s\n", "True");
	} else {
		printf("%s\n", "False");
	}
	printf("%d\n", database->size);
	saveDatabase(database);
	displayDatabase(database);
	database2 = ((MovieDatabase*) malloc(sizeof(MovieDatabase)));
	loadDatabase(database2);
	displayDatabase(database2);
	return 1;
}