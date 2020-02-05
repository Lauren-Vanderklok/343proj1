#include <stdio.h>
//include guards

typedef struct wav_file{
	//"WAVE" format string
	unsigned char wave[4]; // bytes: 8-11

	//"fmt" format string
	unsigned char fmt[4]; //bytes: 12-15 with last byte as null

	//Length of format section
	unsigned int fmtlen; //bytes: 16-19

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
	unsigned int audioSize; //bytes: 40-43
	
	//pointer to audio data
	char* content;
}wav_file;

/*
 * reads .wav data from *contents into wav_file construct
 */
wav_file* parse(char* contents);



