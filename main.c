#include <stdio.h>
#include "wav.h"
#include "file.h"


int main (int argc, char** argv){
	//remember that the first string is the name of the program
	//second is the name of the file and third is the file your reversing to
	//size_t is a number of bytes
	
	char** buffer;
//	char* innerbuffer;
	//buffer = &innerbuffer;
	size_t size;

	size = read_file(argv[1], buffer);
	printf("readfile exited\n");
	if (size == 0){
		//report error, how?
		return -1;
	}

//	char w2 = **buffer;
//	printf("**buffer: %c\n", w2);

	char* innerbuffer;
        innerbuffer = *buffer;
	printf("hereohefsdjnk\n");
	char w2 = **buffer;
	printf("2");
	char w1 = *innerbuffer;
	printf("nwohere");
	printf("*innerbuffer: %c\n", w1);
//
	printf("after\n");

//	wav_file wav;
//	wav = *parse(*buffer);

	//print some file stats
//	printf("File: %s\n", argv[1]);
//	printf("=====================================\n");
//	printf("File size is %i bytes. Read %lu bytes\n", (int) size, wav.audioSize+44);
//        printf("Format is \"%s\" with format data length %lu.\n", wav.fmt, wav.fmtlen);
//	printf("Format type is %sfmt\n", wav.wave);
//	printf("%hu channel(s) with a sample rate of %lu.\n", wav.numChannels, wav.sampleRate);
//	printf("%lu byte rate, %hu alignment, %hu bits per sample.\n", wav.byteRate, wav.blockAlignment, wav.bitSampleRate);
//	printf("Data is \"%s\" and data size is %lu bytes.\n", wav.data, wav. audioSize);
//	printf("=====================================\n");
//	
//	char* reversebuffer;
	//reverse buffer into reverse buffer
	
//	write_file(argv[2], reversebuffer, size);
	return 0;
}


