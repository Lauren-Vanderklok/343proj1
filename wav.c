#include <stdio.h>
#include "wav.h"

wav_file* parse(char* contents){
	//do things? return wav_file
	wav_file wav;
	wav.wave[0] = *contents;
	wav.wave[1] = *(contents+1);
	wav.wave[2] = *(contents+2);
	wav.wave[3] = *(contents+3);
	printf("wave: %s\n", wav.wave);
	wav.fmt[0] = *(contents+4);
	wav.fmt[1] = *(contents+5);
	wav.fmt[2] = *(contents+6);
	wav.fmt[3] = *(contents+7);
	wav.fmtlen = *(contents+8) | (*(contents+9)<<8) | (*(contents+10)<<16) | (*(contents+11)<<24);
	wav.numChannels = *(contents+14) | (*(contents+15)<<8);
	wav.sampleRate = *(contents+16) | (*(contents+17)<<8) | (*(contents+18)<<16) | (*(contents+19)<<24);
	wav.byteRate = *(contents+20) | (*(contents+21)<<8) | (*(contents+22)<<16) | (*(contents+23)<<24);
	wav.blockAlignment = *(contents+24) | (*(contents+25)<<8);
	wav.bitSampleRate = *(contents+26) | (*(contents+27)<<8);
	wav.data[0] = *(contents+28);
	wav.data[1] = *(contents+29);
	wav.data[2] = *(contents+30);
	wav.data[3] = *(contents+31);
	wav.audioSize = *(contents+32) | (*(contents+33)<<8) | (*(contents+34)<<16) | (*(contents+35)<<24);
	wav.content = (contents+36); // there may be 8 extra bytes at the end of this 
}

