#include <stdio.h>
#include "wav.h"
#include "file.h"
#include <stdlib.h>

int main (int argc, char** argv){
	//remember that the first string is the name of the program
	//second is the name of the file and third is the file your reversing to
	//size_t is a number of bytes
	
	char* buffer;
	size_t size;

	size = read_file(argv[1], &buffer);
	printf("readfile exited\n");

	if (size == 0){
		//report error
		return -1;
	}

	//char w = **buffer;
	//printf("**buffer: %c\n", w);

	wav_file* wav;
	wav = parse(buffer);

	//printf("change went thourgh");

	//print some file stats
	printf("File: %s\n", argv[1]);
	printf("=====================================\n");
	printf("File size is %i bytes. Read %i bytes\n", (int) size,(int) (size-44));
        printf("Format is \"%s\" with format data length %lu.\n", wav->fmt, wav->fmtlen);
	printf("Format type is %sfmt\n", wav->wave);
	printf("%hu channel(s) with a sample rate of %u.\n", wav->numChannels, wav->sampleRate);
	printf("%u byte rate, %hu alignment, %hu bits per sample.\n", wav->byteRate, wav->blockAlignment, wav->bitSampleRate);
	printf("Data is \"%s\" and data size is %u bytes.\n", wav->data, wav->audioSize);
	printf("=====================================\n");
	
	//reverse file
	char* reversebuffer;
	reversebuffer = malloc(sizeof(char) * size);
	
	//copy header info into reverse
	for(int i=0; i<44; i++){
		*(reversebuffer+i) = *(buffer+i);
	}
	//actual reversing
	for(int i=size; i>44; i=i-(wav->bitSampleRate/8)){
		//i tracks position in buffer
		int j=44; //j tracks position in reversebuffer

		*(reversebuffer+j) = *(buffer+(i-1));
		*(reversebuffer+(j+1)) = *(buffer+i);

		j=j+(wav->bitSampleRate/8);
	}


	size = write_file(argv[2], reversebuffer, size);

	if (size == 0){
	       //report error
	       return -1;
	}	       
	free(buffer);
	free(reversebuffer);
	free(wav);
	return 0;
}


