/*
File: main.c
Project: imagejs
Author: jklmnn
Homepage: https://https://github.com/jklmnn/imagejs
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gif.h"
#include "bmp.h"

int main(int argc, char *argv[]){
	if(argc < 4){
		printf("ImageJs Version 0.1\n");
		printf("Usage: %s [option] [javascript file] [gif file]\n", argv[0]);
		printf("Options:  gif, bmp\n");
		return 1;
	}
	FILE *in;
	FILE *out;
	int filesize;
	char *buf;
	in = fopen(argv[2], "rb");
	out = fopen(argv[3], "wb");
	fseek(in, 0, SEEK_END);
	filesize = ftell(in);
	rewind(in);
	buf = (char*)malloc(filesize * sizeof(char));
	fread(buf, 1, filesize, in);
	fclose(in);
	char *outbuf;
	if(strcmp(argv[1], "bmp") == 0){
		outbuf = bmp_js(buf, filesize);
		for(int i = 0; i < filesize + BMP_JS_HEADER; i++){
			fprintf(out, "%c", outbuf[i]);
		}
	}
	if(strcmp(argv[1], "gif") == 0){
		outbuf = gif_js(buf, filesize);
		for(int i = 0; i < filesize + GIF_JS_HEADER; i++){
			fprintf(out, "%c", outbuf[i]);
		}
	}
	fclose(out);
	free(buf);
	free(outbuf);
	return 0;
}
	
