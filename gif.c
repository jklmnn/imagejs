/*
File: gif.c
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/


#include "gif.h"

char *gif_js(char *content, int size){
	const char _gif_header[GIF_JS_HEADER] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a, 0x00, 0x30, 0x00, 0x00, 0x3b, 0x2a, 0x2f, 0x3d, 0x30, 0x3b, 0x0a};
	char *buffer = (char*)malloc(GIF_JS_HEADER + size);
	memcpy(buffer, _gif_header, GIF_JS_HEADER);
	memcpy(&buffer[GIF_JS_HEADER], content, size);
	return buffer;
}

char *gif_js_i(char *content, int csize, char *image, int isize){
	const char _gif_header[8] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a};
	const char _gif_header_end[GIF_JS_HEADER_I] = {0x2a, 0x2f, 0x3d, 0x30, 0x3b, 0x0a};
	char *buffer = (char*)malloc(csize + isize + GIF_JS_HEADER_I);
	memcpy(buffer, _gif_header, 8);
	memcpy(&buffer[8], &image[8], isize - 8);
	memcpy(&buffer[isize], _gif_header_end, GIF_JS_HEADER_I);
	memcpy(&buffer[isize + GIF_JS_HEADER_I], content, csize);
	return buffer;
}

char *gif_filename(char *fn, int size){
        const char _gif_ending[GIF_ENDING] = {0x2e, 0x67, 0x69, 0x66, 0x00};
	char *newfile = (char*)malloc(size + GIF_ENDING);
	memcpy(newfile, fn, size);
	memcpy(&newfile[size], _gif_ending, GIF_ENDING);
        return newfile;
}
