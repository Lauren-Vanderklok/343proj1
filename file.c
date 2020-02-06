#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

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

	//fread returns into this, adds one for every sucessful fread call
	int numRead = 0;

	//struct for info about file, needed for finding length of file
	struct stat st;

	file = fopen(filename, "r");

	if (file == NULL){
		printf("errno code: %d\n", errno);
		perror("message");
		return (size_t) 0;
	}

	stat(filename, &st);
	dataSize = st.st_size;

	*buffer = malloc(dataSize);
	
	numRead = fread(*buffer, (size_t) dataSize , 1, file);

	if (numRead != 1){
		printf("errno code: %d\n", errno);
		perror("message");
		return (size_t)  0;
	}

	if (fclose(file) == EOF){
		printf("errno code: %d\n", errno);
		perror("message");
		return (size_t) 0;
	}

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
		printf("errno code: %d\n", errno);
		perror("message");
		return (size_t) 0;
	}

	rtn = fwrite(buffer, size, 1, file);

	if (fclose(file) == EOF){
		printf("errno code: %d\n", errno);
		perror("message");
		return (size_t) 0;
	}

	return rtn;
}

