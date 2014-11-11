/*
File: webp.c
Project: imagejs
Author: jklmnn
Homepage: https://https://github.com/jklmnn/imagejs
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include "webp.h"

char* webp_js(char *content, int size){
	char _webp_header[WEBP_JS_HEADER] = {0x52, 0x49, 0x46, 0x46, 0x3d, 0x30, 0x2f, 0x2f, 0x57, 0x45, 0x42, 0x50, 0x0a};
	char *buffer = (char*)malloc(WEBP_JS_HEADER + size);
	for(int i = 0; i < WEBP_JS_HEADER; i++){
		buffer[i] = _webp_header[i];
	}
	for(int i = 0; i < size; i++){
		buffer[i+WEBP_JS_HEADER] = content[i];
	}
	return buffer;
}

char *webp_filename(char *fn, int size){
	char _webp_ending[WEBP_ENDING] = {0x2e, 0x77, 0x65, 0x62, 0x70, 0x00};
	char *newfile = (char*)malloc(size + WEBP_ENDING);
	for(int i = 0; i < size; i++){
		newfile[i] = fn[i];
	}
	for(int i = 0; i < WEBP_ENDING; i++){
		newfile[size + i] = _webp_ending[i];
	}
	return newfile;
}
