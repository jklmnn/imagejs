/*
File: webp.c
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include "webp.h"

char* webp_js(char *content, int size){
	const char _webp_header[WEBP_JS_HEADER] = {0x52, 0x49, 0x46, 0x46, 0x3d, 0x30, 0x2f, 0x2f, 0x57, 0x45, 0x42, 0x50, 0x0a};
	char *buffer = (char*)malloc(WEBP_JS_HEADER + size);
	memcpy(buffer, _webp_header, WEBP_JS_HEADER);
	memcpy(&buffer[WEBP_JS_HEADER], content, size);
	return buffer;
}

char *webp_filename(char *fn, int size){
	const char _webp_ending[WEBP_ENDING] = {0x2e, 0x77, 0x65, 0x62, 0x70, 0x00};
	char *newfile = (char*)malloc(size + WEBP_ENDING);
	memcpy(newfile, fn, size);
	memcpy(&newfile[size], _webp_ending, WEBP_ENDING);
	return newfile;
}
