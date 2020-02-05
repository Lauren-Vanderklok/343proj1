#include <stdio.h>
//include guards

typedef struct wav_file{
	unsigned char wave[4]; //8-11
	unsigned char fmt[4]; //12-15 with last as null
	unsigned int fmtlen; //16-19
	unsigned short numChannels; //22-23
	unsigned int sampleRate; //24-27
	unsigned int byteRate; //28-31
	unsigned short blockAlignment; //32-33
	unsigned short bitSampleRate; //34-35
	unsigned char data[4]; //36-39
	unsigned int audioSize; //40-43
	char* content;
}wav_file;

wav_file* parse(char* contents);



