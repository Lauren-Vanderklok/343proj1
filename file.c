#include "file.h"
#include <stdlib.h>
#include <stdio.h>

size_t read_file (char* filename, char** buffer){
	//read file
	FILE* file;
	unsigned int dataSize;
	unsigned char riff[4];
	unsigned char buff4[4];
	int numRead = 0;

	file = fopen(filename, "r");

	if (file == NULL){
		return (size_t) 0;
	}

	numRead = numRead + fread(riff, sizeof(riff), 1, file);
	//printf("%i\n", numRead);
	numRead = numRead + fread(buff4, sizeof(buff4), 1, file);
	printf("buff4 before endian conversion: %u %u %u %u\n", buff4[0], buff4[1], buff4[2], buff4[3]);
	printf("riff raw: %u %u %u %u\n", riff[0], riff[1], riff[2], riff[3]);
	//printf("%i\n", numRead);
	//dataSize = buff4[0] | (buff4[1]<<8) | (buff4[2]<<16) | (buff4[3]<<24);
	//printf("buff4 after endian conversion?: %u %u %u %u\n", buff4[0], buff4[1], buff4[2], buff4[3]); 

	//JUST IN FOR TESTING
	dataSize = 1155142;

	*buffer = malloc(sizeof(riff) + sizeof(buff4) + dataSize);

	//this copies the raw data that i just took into the buffer so i dont have to worry about endian later
	for (int i=0; i<4; i++){
		*(*buffer+i) = riff[i];
	}
	for (int i=4; i<8; i++){
		*(*buffer+i) = buff4[i];
		//printf("%u ", *(*buffer+i));
	}
	//printf("\n");
	for (int i=0; i<8; i++){
		//printf("%u ", *(*buffer+i));
	}
	//printf("\n");

	for (int i=0; i<8; i++){
		//printf("%c ", *(*buffer+i));
	}
	//printf("\n");

	if (numRead != 2){
		return (size_t) 0;
	}

	printf("%s\n", riff);
	printf("%lu\n", dataSize);
	//printf("you have no idea how much i hope thats right");
	//printf("before mallocing *buffer\n");

	//*buffer = malloc(dataSize);

	//printf("before freading file into *buffer\n");

	numRead = numRead + fread((*buffer+8), (size_t) (dataSize-8) , 1, file);
	printf("%i\n", numRead);
	printf("*buffer+8: %p\n", (void*)(*buffer+8));

	

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

