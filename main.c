#include <stdio.h>
#include "wav.h"
#include "file.h"


int main (int argc, char** argv){
	//remember that the first string is the name of the program
	//second is the name of the file and third is the file your reversing to
	//size_t is a number of bytes
	
	char** buffer;
	size_t size;

	size = read_file(argv[1], buffer);
	
	if (size == 0){
		//report error, how?
		return -1;
	}

	wav_file wav;
	wav = *parse(*buffer);

	//print some file stats
	
	char* reversebuffer;
	//reverse buffer into reverse buffer
	
	write_file(argv[2], reversebuffer, size);
}


