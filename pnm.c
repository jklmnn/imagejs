/*
File: pnm.c
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/

#include "pnm.h"

char *pnm_js(char *content, int size){
	const char _pnm_header[PNM_JS_HEADER] = {0x50, 0x36, 0x2f, 0x2a, 0x0a, 0x32, 0x20, 0x32, 0x0a, 0x32, 0x35, 0x35, 0x0a, 0x2a, 0x2f, 0x3d, 0x30, 0x3b, 0x0a};
	char *buffer = (char*)malloc(PNM_JS_HEADER + size);
	memcpy(buffer, _pnm_header, PNM_JS_HEADER);
	memcpy(&buffer[PNM_JS_HEADER], content, size);
	return buffer;
}

char *pnm_filename(char *fn, int size){
	const char _pnm_ending[PNM_ENDING] = {0x2e, 0x70, 0x6e, 0x6d, 0x00};
	char *newfile = (char*)malloc(size + PNM_ENDING);
	memcpy(newfile, fn, size);
	memcpy(&newfile[size], _pnm_ending, PNM_ENDING);
	return newfile;
}
