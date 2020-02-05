#include <stdio.h>
#include <stdlib.h>
#include "wav.h"

wav_file* parse(char* contents){
	//do things? return wav_file
	wav_file* wav;
	wav = malloc(sizeof(wav_file));
	wav->wave[0] = *(contents+8);
	wav->wave[1] = *(contents+9);
	wav->wave[2] = *(contents+10);
	wav->wave[3] = *(contents+11);
	printf("wave: %s\n", wav->wave);
	wav->fmt[0] = *(contents+12);
	wav->fmt[1] = *(contents+13);
	wav->fmt[2] = *(contents+14);
	wav->fmt[3] = *(contents+15);
	wav->fmtlen = *(contents+16) | (*(contents+17)<<8) | (*(contents+18)<<16) | (*(contents+19)<<24);
	wav->numChannels = *(contents+22) | (*(contents+23)<<8);
	wav->sampleRate = *(contents+24) | (*(contents+25)<<8) | (*(contents+26)<<16) | (*(contents+27)<<24);
	//printf("sampleRate: %lu, %i\n", wav->sampleRate, wav->sampleRate);
	//printf("sampleRate(nonEndian): %lu\n", ((*contents+16) | *(contents+17) | *(contents+18) | *(contents+19)));
	//printf("sampleRate(nonEndian)(signed): %i\n", ((*contents+16) | *(contents+17) | *(contents+18) | *(contents+19)));
	wav->byteRate = *(contents+28) | (*(contents+29)<<8) | (*(contents+30)<<16) | (*(contents+31)<<24);
	wav->blockAlignment = *(contents+32) | (*(contents+33)<<8);
	wav->bitSampleRate = *(contents+34) | (*(contents+35)<<8);
	wav->data[0] = *(contents+36);
	wav->data[1] = *(contents+37);
	wav->data[2] = *(contents+38);
	wav->data[3] = *(contents+39);
	wav->audioSize = *(contents+40) | (*(contents+41)<<8) | (*(contents+42)<<16) | (*(contents+43)<<24);
	//printf("audioSize: %lu, %u, %i\n", wav->audioSize, wav->audioSize, wav->audioSize);
	//printf("audioSize: 24,8,8,24 endian(now +): %u\n", ((*(contents+32)<<24) + (*(contents+33)<<8) + (*(contents+34)>>8) + (*(contents+35)>>24)));
	//printf("audioSIze: 24, 8, 8, 24, endian (+) reversed byte order; %u\n", ((*(contents+35)<<24) + (*(contents+34) << 8) + (*(contents+33)>>8) + (*(contents+32)>>24)));
	//printf("audiosize: not adjusted for endianess: %u\n", (*(contents+32) | *(contents+33) | *(contents+34) | *(contents+35)));
	//printf("audiosize 0,8,16,24 endian adjust: %u\n", (*(contents+32) | (*(contents+33)<<8) | (*(contents+34)<<16) | (*(contents+35)<<24)));
	//printf("audiosize byteswap1(passing single address: %u \n", ByteSwap1((long) *contents+32));

	wav->content = (contents+44); // there may be 8 extra bytes at the end of this //no longer!
	return wav;
}


