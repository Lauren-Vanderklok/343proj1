#import "file.h"
#include <stdlib.h>
#include <stdio.h>

size_t read_file (char* filename, char** buffer){
	//read fie
	//size t is bytes
	FILE* file;
	char* fgetsReturn;
	char* first44;
	size_t dataSize;

	file = fopen(filename, "r");

	if (file == NULL){
		return (size_t) 0;
	}

	first44 = malloc(67); //need extra byte because fgets puts a null char at end?????

	fgetsReturn = fgets(first44, 67, file); //add extra byte for null char

	if (fgetsReturn == NULL){
		return (size_t) 0;
	}
	printf("all: %s\n", first44);
	printf("should read data: %c%c%c%c\n", *(&first44 + 36), *(&first44 + 37), *(&first44 + 38), *(&first44 + 39)); //test
	unsigned int testsize;
	testsize = *(&first44 + 40);
	printf("size of data: %i\n", testsize);
	dataSize = (size_t) (*(&first44 + 41) + 44); //honestly not sure if i should use 41 or 40 here
	
	*buffer = malloc(dataSize);

	fgetsReturn = fgets(*buffer, ((int) dataSize) + 1, file);

	if (fgetsReturn == NULL){
		return (size_t)  0;
	}

	return dataSize;

}

size_t write_file (char* filename, char* buffer, size_t size){
	//write to a file i guess
}

