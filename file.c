#include "file.h"
#include <stdlib.h>
#include <stdio.h>

size_t read_file (char* filename, char** buffer){
	//read file
	FILE* file;
	unsigned int dataSize;
	char riff[4];
	unsigned char buff4[4];
	int numRead;
//	char* innerbuffer;
//	innerbuffer = *buffer;

	file = fopen(filename, "r");

	if (file == NULL){
		return (size_t) 0;
	}

	numRead = fread(riff, sizeof(riff), 1, file);
	numRead = numRead + fread(buff4, sizeof(buff4), 1, file);
	dataSize = buff4[0] | (buff4[1]<<8) | (buff4[2]<<16) | (buff4[3]<<24);

	*buffer = malloc(sizeof(riff) + sizeof(buff4) + dataSize);

	//this copies the raw data that i just took into the buffer so i dont have to worry about endian later
	for (int i=0; i<4; i++){
		*(*buffer+i) = riff[i];
	}
	for (int i=4; i<8; i++){
		*(*buffer+i) = buff4[i];
	}

	if (numRead != 2){
		return (size_t) 0;
	}

	printf("%s\n", riff);
	printf("%lu\n", dataSize);
	//printf("you have no idea how much i hope thats right");
	//printf("before mallocing *buffer\n");

	//*buffer = malloc(dataSize);

	//printf("before freading file into *buffer\n");

	numRead = numRead + fread((*buffer+8), (size_t) dataSize, 1, file);

	//printf("before accessing **buffer\n");

	char w2 = **buffer;
	printf("buffer: %c\n", w2);

	if (numRead != 3){
		return (size_t)  0;
	}

	printf("readfile is about to return\n");


	if (fclose(file) == EOF){
		return (size_t) 0;
	}

	return (size_t) dataSize;

}

size_t write_file (char* filename, char* buffer, size_t size){
	//write to a file i guess
	FILE* file;
	size_t rtn=0;

	file = fopen(filename, "w");

	if (file == NULL){
		return (size_t) 0;
	}

	rtn = fwrite(buffer, size, 1, file);

	if (fclose(file) == EOF){
		return (size_t) 0;
	}

	return rtn;
}

