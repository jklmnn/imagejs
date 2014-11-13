/*
File: pgf.c
Project: imagejs
Author: jklmnn
Homepage: http://jklmnn.de/imagejs/
License: GNU GENERAL PUBLIC LICENSE Version 3
*/


#include "pgf.h"

char *pgf_js(char *content, int size){
	const char _pgf_header[PGF_JS_HEADER] = {0x50, 0x47, 0x46, 0x31, 0x2f, 0x2a, 0x00, 0x0a, 0x2a, 0x2f, 0x3d, 0x31, 0x3b, 0x0a};
	char *buffer = (char*)malloc(PGF_JS_HEADER + size);
	memcpy(buffer, _pgf_header, PGF_JS_HEADER);
	memcpy(&buffer[PGF_JS_HEADER], content, size);
	return buffer;
}

char *pgf_filename(char *fn, int size){
	const char _pgf_ending[PGF_ENDING] = {0x2e, 0x70, 0x67, 0x66, 0x00};
	char *newfile = (char*)malloc(size + PGF_ENDING);
	memcpy(newfile, fn, size);
	memcpy(&newfile[size], _pgf_ending, PGF_ENDING);
	return newfile;
}
