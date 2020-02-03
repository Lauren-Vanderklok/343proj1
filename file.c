#import "file.h"
#include <stdlib.h>
#include <stdio.h>

size_t read_file (char* filename, char** buffer){
	//read fie
	FILE* file;
	unsigned int dataSize;
	unsigned char riff[4];
	unsigned char buff4[4];
	int numRead;
//	char* innerbuffer;
//	innerbuffer = *buffer;

	file = fopen(filename, "r");

	if (file == NULL){
		return (size_t) 0;
	}

	//first44 = malloc(sizeof(char)*67); //need extra byte because fgets puts a null char at end?????
	//fgetsReturn = fgets(first44, 67, file); //add extra byte for null char

	numRead = fread(riff, sizeof(riff), 1, file);
	numRead = numRead + fread(buff4, sizeof(buff4), 1, file);
	dataSize = buff4[0] | (buff4[1]<<8) | (buff4[2]<<16) | (buff4[3]<<24);

	if (numRead != 2){
		return (size_t) 0;
	}
	//printf("what?");
	printf("%s\n", riff);
	printf("%lu\n", dataSize);
	//printf("hello???????");
	//printf("before mallocing *buffer?");

	*buffer = malloc(dataSize);

	//printf("before fread");

	numRead = numRead + fread(*buffer, (size_t) dataSize, 1, file);

	//printf("right before im trying to access first value\n");
//	char w = *innerbuffer;
//	printf("innerbuffer: %c\n", w);
	char w2 = **buffer;
	printf("buffer: %c\n", w2);

	//fgetsReturn = fgets(*buffer, ((int) dataSize) + 1, file);

	if (numRead != 3){
		return (size_t)  0;
	}
	printf("readfile is about to return\n");
	return (size_t) dataSize;

}

size_t write_file (char* filename, char* buffer, size_t size){
	//write to a file i guess
}

