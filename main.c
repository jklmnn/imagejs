/*
File: main.c
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "meta.h"
#include "gif.h"
#include "bmp.h"
#include "webp.h"

int getlen(char* str){
	int i;
	for(i = 0; str[i] != 0; i++);
	return i;
}

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("ImageJs Version %d.%d.%d\n", VERSION_MAJ, VERSION_MIN, VERSION_FIX);
		printf("Usage: %s [option] [javascript file]\n", argv[0]);
		printf("Options:  gif, bmp, webp\n");
		return 1;
	}
	FILE *in;
	FILE *out;
	int filesize;
	char *buf;
	in = fopen(argv[2], "rb");
	fseek(in, 0, SEEK_END);
	filesize = ftell(in);
	rewind(in);
	buf = (char*)malloc(filesize * sizeof(char));
	fread(buf, 1, filesize, in);
	fclose(in);
	char *outbuf;
	if(strcmp(argv[1], "bmp") == 0){
		outbuf = bmp_js(buf, filesize);
		out = fopen(bmp_filename(argv[2], getlen(argv[2])), "wb");
		for(int i = 0; i < filesize + BMP_JS_HEADER; i++){
			fprintf(out, "%c", outbuf[i]);
		}
	}
	if(strcmp(argv[1], "gif") == 0){
		outbuf = gif_js(buf, filesize);
		out = fopen(gif_filename(argv[2], getlen(argv[2])), "wb");
		for(int i = 0; i < filesize + GIF_JS_HEADER; i++){
			fprintf(out, "%c", outbuf[i]);
		}
	}
	if(strcmp(argv[1], "webp") == 0){
		outbuf = webp_js(buf, filesize);
		out = fopen(webp_filename(argv[2], getlen(argv[2])), "wb");
		for(int i = 0; i < filesize + WEBP_JS_HEADER; i++){
			fprintf(out, "%c", outbuf[i]);
		}
	}
	fclose(out);
	free(buf);
	free(outbuf);
	return 0;
}
	
