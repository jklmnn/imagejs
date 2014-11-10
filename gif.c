/*
File: gif.c
Project: imagejs
Author: jklmnn
Homepage: https://https://github.com/jklmnn/imagejs
License: GNU GENERAL PUBLIC LICENSE Version 3
*/


#include "gif.h"

char* gif_js(char *content, int size){
	char _gif_header[GIF_JS_HEADER] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a, 0x00, 0x30, 0x00, 0x00, 0x3b, 0x2a, 0x2f, 0x3d, 0x30, 0x0a};
	char *buffer = (char*)malloc(GIF_JS_HEADER + size);
	for(int i = 0; i < GIF_JS_HEADER; i++){
		buffer[i] = _gif_header[i];
	}
	for(int i = 0; i < size; i++){
		buffer[i+GIF_JS_HEADER] = content[i];
	}
	return buffer;
}

char *gif_filename(char *fn, int size){
        char _gif_ending[GIF_ENDING] = {0x2e, 0x67, 0x69, 0x66, 0x00};
	char *newfile = (char*)malloc(size + GIF_ENDING);
        for(int i = 0; i < size; i++){
                newfile[i] = fn[i];
        }
	for(int i = 0; i < GIF_ENDING; i++){
		newfile[size + i] = _gif_ending[i];
	}
        return newfile;
}
