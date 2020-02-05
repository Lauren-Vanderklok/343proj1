#include "file.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * reads data from filename file
 * inner pointer of double pointer parameter points to data
 * returns 0 if there is an error, size of data in bytes if not
 */
size_t read_file (char* filename, char** buffer){
	//file being read from
	FILE* file;

	//size of data in .wav file
	unsigned int dataSize;

	//RIFF header of .wav file
	unsigned char riff[4];

	//char array to hold individual bytes of dataSize before translation
	unsigned char buff4[4];

	//fread returns into this, adds one for every sucessful fread call
	int numRead = 0;

	file = fopen(filename, "r");

	if (file == NULL){
		return (size_t) 0;
	}

	numRead = numRead + fread(riff, sizeof(riff), 1, file);
	numRead = numRead + fread(buff4, sizeof(buff4), 1, file);
	printf("buff4 before endian conversion: %u %u %u %u\n", buff4[0], buff4[1], buff4[2], buff4[3]);
	printf("riff chars: %u %u %u %u\n", riff[0], riff[1], riff[2], riff[3]);

	//dataSize = buff4[0] | (buff4[1]<<8) | (buff4[2]<<16) | (buff4[3]<<24);
	

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
	
	printf("buffer data: ");
	for (int i=0; i<8; i++){
		printf("%u ", *(*buffer+i));
	}
	printf("\n");

	//for (int i=0; i<8; i++){
		//printf("%c ", *(*buffer+i));
	//}
	//printf("\n");

	if (numRead != 2){
		return (size_t) 0;
	}

	//printf("%s\n", riff);
	//printf("%u\n", dataSize);

	//reads remaining info into buffer, have to add 8 to address to not overwrite 
	numRead = numRead + fread((*buffer+8), (size_t) (dataSize-8) , 1, file);

	if (numRead != 3){
		return (size_t)  0;
	}

	if (fclose(file) == EOF){
		return (size_t) 0;
	}

	printf("readfile sucessful");

	return (size_t) dataSize;

}

/*
 * writes contents of buffer of size size to filename file
 * returns 0 if there is an error
 */
size_t write_file (char* filename, char* buffer, size_t size){
	//file being written to
	FILE* file;

	//return value
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

