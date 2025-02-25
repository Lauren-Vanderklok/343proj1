#include <stdio.h>
//include guards

typedef struct wav_file{
	
	//holds "RIFF" header
	unsigned char riff[4]; //bytes: 0-3

	//size of the whole file, includeing header
	unsigned int totalSize; //bytes: 4-7

	//"WAVE" format string
	unsigned char wave[4]; // bytes: 8-11

	//"fmt" format string
	unsigned char fmt[4]; //bytes: 12-15 with last byte as null

	//Length of format section
	unsigned int fmtlen; //bytes: 16-19

	//type of fmt block
	unsigned short fmtType; //bytes 20-21

	//Number of audio channels 
	unsigned short numChannels; //bytes: 22-23

	//Sample rate
	unsigned int sampleRate; //bytes: 24-27

	//Byte rate
	unsigned int byteRate; //bytes: 28-31

	//Block alignment
	unsigned short blockAlignment; //bytes: 32-33

	//bits per sample
	unsigned short bitSampleRate; //bytes: 34-35

	//'data' string, start of data section
	unsigned char data[4]; //bytes: 36-39

	//size of audio data in bytes
	int audioSize; //bytes: 40-43
	
	//pointer to audio data
	char* content;
}wav_file;

/*
 * reads .wav data from *contents into wav_file construct
 */
wav_file* parse(char* contents);



