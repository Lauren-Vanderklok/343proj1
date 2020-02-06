#include <stdio.h>
#include "wav.h"
#include "file.h"
#include <stdlib.h>

int main (int argc, char** argv){
	//argv[1] is the name of the file to reverse and argv[2] is the file your reversing to
	
	//raw data from the .wav file, stored in heap
	char* buffer;

	//size of buffer in bytes
	size_t size;

	//pointer to struct to hold .wav audio and header info
	wav_file* wav;

	size = read_file(argv[1], &buffer);

	if (size == 0){
		//report error
		fprintf(stderr, "read_file failed");
		printf("read_file failed\n");
		return -1;
	}

	wav = parse(buffer);

	//print some file stats
	printf("File: %s\n", argv[1]);
	printf("=====================================\n");
	printf("File size is %i bytes. Read %i bytes\n", (int) size,(int) (size-44));
        printf("Format is \"%s\" with format data length %u.\n", wav->fmt, wav->fmtlen);
	printf("Format type is %sfmt\n", wav->wave);
	printf("%hu channel(s) with a sample rate of %u.\n", wav->numChannels, wav->sampleRate);
	printf("%u byte rate, %hu alignment, %hu bits per sample.\n", wav->byteRate, wav->blockAlignment, wav->bitSampleRate);
	printf("Data is \"%s\" and data size is %u bytes.\n", wav->data, wav->audioSize);
	printf("=====================================\n");
	
	printf("first 10 bytes in buffer: ");
	for (int i=44; i<54; i++){
		printf("%u ", *(buffer+i));
	}
	printf("\n");
	printf("last 10 bytes in buffer: ");
	for (int i=(size-10); i<size; i++){
		printf("%u ", *(buffer+i));
	}
	printf("\n///////////////////////////////////////");
	

	//long start = 44;
	//long end = size;
	
	//int bytesPerSample = wav->bitSampleRate;

	//while (start < end){
	//	char temp = buffer[start];
	//	buffer[start] = buffer[end-1];
	//	buffer[end-1] = temp;
	//	temp = buffer[start+1];
	//	buffer[start+1] = buffer[end];
	//	buffer[end] = temp;
	//	start += bytesPerSample;
	//	end -= bytesPerSample;
	//}






	char temp;

	for(int i=44; i<((size-44)/2); i++){
		int j = size;
		temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
		j--;
	}

	for(int i=44; i<size; i=i+2){
		temp = buffer[i];
		buffer[i] = buffer[i+1];
		buffer[i+1] = temp;
	}


	printf("\nfirst 10 bytes in buffer: ");
	for (int i=44; i<54; i++){
		printf("%u ", *(buffer+i));
	}
	printf("\nlast 10 bytes in buffer: ");
	for (int i=(size-10); i<size; i++){
		printf("%u ", *(buffer+i));
	}

	printf("\n");	


	//	temp[0] = *(buffer+i);
	//	temp[1] = *(buffer+i+1);
	//	*(buffer+i) = *(buffer+j-1);
	//	*(buffer+i+1) = *(buffer+j);
	//	*(buffer+j-1) = temp[0];
	//	*(buffer+j) = temp[1];

	size = write_file(argv[2], buffer, size);

	if (size == 0){
	       //report error
	       fprintf(stderr, "write_file failed");
	       printf("write_file failed");
	       return -1;
	}	       
	free(buffer);
	return 0;
}


