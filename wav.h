#import <stdio.h>
//include guards

typedef struct wav_file{
	short format; //says FormatType bytes 20-21
	int formatLength //says its the length of the format section bytes 16-19
	int fileSize; //not just the size of the data
	short numChannels;
	int sampleRate;
	int byteRate;
	short blockAlignment;
	short bitSampleRate;
	char* content;
}wav_file;

wav_file* parse(char* contents);

