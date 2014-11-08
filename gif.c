#include "gif.h"

char* generate(char *content, int size){
	char _gif_header[18] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x2f, 0x2a, 0x00, 0x30, 0x00, 0x00, 0x3b, 0x2a, 0x2f, 0x3d, 0x30, 0x0a};
	char *buffer = (char*)malloc(18 + size);
	for(int i = 0; i < 18; i++){
		buffer[i] = _gif_header[i];
	}
	for(int i = 0; i < size; i++){
		buffer[i+18] = content[i];
	}
	return buffer;
}

